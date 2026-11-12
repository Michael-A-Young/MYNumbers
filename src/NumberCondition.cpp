/**
@file
	NumberCondition.cpp
@brief
	A composable condition over a single number.
*/

#include "NumberCondition.h"

// MYNumbers
#include "NumberClassifier.h"

// Standard Library
#include <utility>

namespace MY
{

NumberCondition NumberCondition::Type(NumberTypeID typeID)
{
	NumberCondition result(Kind::Type);
	result.mType = typeID;
	return result;
}

NumberCondition NumberCondition::RelatesTo(NumberRelationshipType type, Number operand)
{
	NumberCondition result(Kind::RelatesTo);
	result.mRelationshipType = type;
	result.mOperand = operand;
	return result;
}

NumberCondition NumberCondition::RelatesFrom(NumberRelationshipType type, Number operand)
{
	NumberCondition result(Kind::RelatesFrom);
	result.mRelationshipType = type;
	result.mOperand = operand;
	return result;
}

NumberCondition NumberCondition::Not(NumberCondition condition)
{
	NumberCondition result(Kind::Not);
	result.mChildren.push_back(std::move(condition));
	return result;
}

NumberCondition NumberCondition::All(std::vector<NumberCondition> conditions)
{
	NumberCondition result(Kind::All);
	result.mChildren = std::move(conditions);
	return result;
}

NumberCondition NumberCondition::Any(std::vector<NumberCondition> conditions)
{
	NumberCondition result(Kind::Any);
	result.mChildren = std::move(conditions);
	return result;
}

bool NumberCondition::Matches(Number value, const NumberClassifier& classifier) const
{
	bool result = false;

	switch (mKind)
	{
		case Kind::Type:
		{
			result = classifier.IsType(value, mType);
			break;
		}
		case Kind::RelatesTo:
		{
			result = classifier.Holds(mRelationshipType, value, mOperand);
			break;
		}
		case Kind::RelatesFrom:
		{
			result = classifier.Holds(mRelationshipType, mOperand, value);
			break;
		}
		case Kind::Not:
		{
			if (!mChildren.empty())
			{
				result = !mChildren.front().Matches(value, classifier);
			}
			break;
		}
		case Kind::All:
		{
			result = true;

			for (const NumberCondition& child : mChildren)
			{
				if (!child.Matches(value, classifier))
				{
					result = false;
				}
			}
			break;
		}
		case Kind::Any:
		{
			result = false;

			for (const NumberCondition& child : mChildren)
			{
				if (child.Matches(value, classifier))
				{
					result = true;
				}
			}
			break;
		}
		default:
		{
			break;
		}
	}

	return result;
}

NumberCondition::NumberCondition(Kind kind)
	: mKind(kind)
	, mType(NumberTypeID::Invalid)
	, mRelationshipType(NumberRelationshipType::Invalid)
	, mOperand(0)
	, mChildren()
{
}

} // namespace MY
