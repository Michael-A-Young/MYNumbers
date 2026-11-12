/**
@file
	NumberClassifier.h
@brief
	Orchestrator and public interface to the number classification framework.
*/

#ifndef MY_NUMBER_CLASSIFIER_H
#define MY_NUMBER_CLASSIFIER_H

// MYNumbers
#include "BuiltInNumbers.h"
#include "NumberCache.h"
#include "TypeRegistry.h"
#include "NumberRelationship.h"
#include "NumberRelationshipType.h"
#include "NumberSequence.h"
#include "NumberSequenceType.h"
#include "NumberType.h"
#include "NumberTypeID.h"

// Standard Library
#include <map>
#include <optional>

namespace MY
{

using NumberClassification = std::map<NumberTypeID, bool>;

class NumberQuery;

class NumberClassifier
{
public:
	NumberClassifier();

	NumberClassifier(const NumberClassifier& other) = delete;
	NumberClassifier(NumberClassifier&& other) = default;

	NumberClassifier& operator=(const NumberClassifier& other) = delete;
	NumberClassifier& operator=(NumberClassifier&& other) = default;

	~NumberClassifier() = default;

public:
	NumberTypeID RegisterType(NumberType& type);
	bool RegisterType(NumberType& type, NumberTypeID typeID);

	NumberSequenceType RegisterSequence(NumberSequence& sequence);
	bool RegisterSequence(NumberSequence& sequence, NumberSequenceType type);

	NumberRelationshipType RegisterRelationship(NumberRelationship& relationship);
	bool RegisterRelationship(NumberRelationship& relationship, NumberRelationshipType type);

	NumberClassification GetTypes(Number value) const;
	bool IsType(Number value, NumberTypeID typeID) const;

	void Search(const NumberQuery& query, Numbers& outNumbers) const;

	Number GetNth(NumberSequenceType type, Index index) const;
	std::optional<Index> GetIndex(NumberSequenceType type, Number value) const;

	bool Holds(NumberRelationshipType type, Number left, Number right) const;

private:
	void RegisterBuiltInTypes();

private:
	NumberCache mCache;
	BuiltInNumbers mBuiltIns;
	TypeRegistry<NumberType> mTypeRegistry;
	TypeRegistry<NumberSequence> mSequenceRegistry;
	TypeRegistry<NumberRelationship> mRelationshipRegistry;
};

} // namespace MY

#endif // MY_NUMBER_CLASSIFIER_H
