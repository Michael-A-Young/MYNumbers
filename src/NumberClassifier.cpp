/**
@file
	NumberClassifier.cpp
@brief
	Orchestrator and public interface to the number classification framework.
*/

#include "NumberClassifier.h"

// MYNumbers
#include "NumberQuery.h"

// Standard Library
#include <chrono>
#include <limits>
#include <vector>

namespace MY
{

NumberClassifier::NumberClassifier()
	: mCache()
	, mBuiltIns()
	, mTypeRegistry(static_cast<uint32_t>(NumberTypeID::FirstCustom))
	, mSequenceRegistry(static_cast<uint32_t>(NumberSequenceType::FirstCustom))
	, mRelationshipRegistry(static_cast<uint32_t>(NumberRelationshipType::FirstCustom))
{
	RegisterBuiltInTypes();
}

NumberTypeID NumberClassifier::RegisterType(NumberType& type)
{
	const uint32_t typeID = mTypeRegistry.Register(type);
	return static_cast<NumberTypeID>(typeID);
}

bool NumberClassifier::RegisterType(NumberType& type, NumberTypeID typeID)
{
	return mTypeRegistry.Register(type, static_cast<uint32_t>(typeID));
}

NumberSequenceType NumberClassifier::RegisterSequence(NumberSequence& sequence)
{
	const uint32_t sequenceType = mSequenceRegistry.Register(sequence);
	return static_cast<NumberSequenceType>(sequenceType);
}

bool NumberClassifier::RegisterSequence(NumberSequence& sequence, NumberSequenceType type)
{
	return mSequenceRegistry.Register(sequence, static_cast<uint32_t>(type));
}

NumberRelationshipType NumberClassifier::RegisterRelationship(NumberRelationship& relationship)
{
	const uint32_t relationshipType = mRelationshipRegistry.Register(relationship);
	return static_cast<NumberRelationshipType>(relationshipType);
}

bool NumberClassifier::RegisterRelationship(NumberRelationship& relationship, NumberRelationshipType type)
{
	return mRelationshipRegistry.Register(relationship, static_cast<uint32_t>(type));
}

NumberClassification NumberClassifier::GetTypes(Number value) const
{
	NumberClassification result;
	std::vector<uint32_t> typeIDs;
	mTypeRegistry.GetIDs(typeIDs);

	for (const uint32_t typeID : typeIDs)
	{
		const NumberType* type = mTypeRegistry.Get(typeID);
		bool isMember = false;

		if (type != nullptr)
		{
			isMember = type->IsMember(value);
		}

		result.emplace(static_cast<NumberTypeID>(typeID), isMember);
	}

	return result;
}

bool NumberClassifier::IsType(Number value, NumberTypeID typeID) const
{
	bool result = false;
	const NumberType* type = mTypeRegistry.Get(static_cast<uint32_t>(typeID));

	if (type != nullptr)
	{
		result = type->IsMember(value);
	}

	return result;
}

void NumberClassifier::Search(const NumberQuery& query, Numbers& outNumbers) const
{
	outNumbers.clear();

	NumberRanges ranges = query.GetRanges();
	const std::optional<size_t> maxResults = query.GetMaxResults();
	const std::optional<std::chrono::milliseconds> maxTime = query.GetMaxTime();
	const std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
	const bool limited = maxResults.has_value() || maxTime.has_value();

	if (ranges.empty() && limited)
	{
		ranges.push_back(NumberRange{0, std::numeric_limits<Number>::max()});
	}

	bool done = maxResults.has_value() && maxResults.value() == 0;

	for (const NumberRange& range : ranges)
	{
		Number value = range.first;

		while (!done)
		{
			if (maxTime.has_value() && std::chrono::steady_clock::now() - startTime >= maxTime.value())
			{
				done = true;
				break;
			}

			if (query.Matches(value))
			{
				outNumbers.push_back(value);

				if (maxResults.has_value() && outNumbers.size() >= maxResults.value())
				{
					done = true;
					break;
				}
			}

			if (value == range.last)
			{
				break;
			}

			++value;
		}

		if (done)
		{
			break;
		}
	}
}

Number NumberClassifier::GetNth(NumberSequenceType type, Index index) const
{
	Number result = 0;
	const NumberSequence* sequence = mSequenceRegistry.Get(static_cast<uint32_t>(type));

	if (sequence != nullptr)
	{
		result = sequence->GetNth(index);
	}

	return result;
}

std::optional<Index> NumberClassifier::GetIndex(NumberSequenceType type, Number value) const
{
	std::optional<Index> result;
	const NumberSequence* sequence = mSequenceRegistry.Get(static_cast<uint32_t>(type));

	if (sequence != nullptr)
	{
		result = sequence->GetIndex(value);
	}

	return result;
}

bool NumberClassifier::Holds(NumberRelationshipType type, Number left, Number right) const
{
	bool result = false;
	const NumberRelationship* relationship = mRelationshipRegistry.Get(static_cast<uint32_t>(type));

	if (relationship != nullptr)
	{
		result = relationship->Holds(left, right);
	}

	return result;
}

void NumberClassifier::RegisterBuiltInTypes()
{
	mBuiltIns.RegisterTypes(&mTypeRegistry);
	mBuiltIns.RegisterSequences(&mSequenceRegistry);
	mBuiltIns.RegisterRelationships(&mRelationshipRegistry);
}

} // namespace MY
