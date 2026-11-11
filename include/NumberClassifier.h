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
#include "NumberRelationship.h"
#include "NumberRelationshipRegistry.h"
#include "NumberRelationshipType.h"
#include "NumberSequence.h"
#include "NumberSequenceRegistry.h"
#include "NumberSequenceType.h"
#include "NumberType.h"
#include "NumberTypeID.h"
#include "NumberTypeRegistry.h"

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
	NumberCache& GetCache();
	const NumberCache& GetCache() const;

	NumberTypeID RegisterType(NumberType& type);
	bool RegisterType(NumberType& type, NumberTypeID id);

	NumberSequenceType RegisterSequence(NumberSequence& sequence);
	bool RegisterSequence(NumberSequence& sequence, NumberSequenceType type);

	NumberRelationshipType RegisterRelationship(NumberRelationship& relationship);
	bool RegisterRelationship(NumberRelationship& relationship, NumberRelationshipType type);

	NumberClassification GetTypes(Number value) const;
	bool IsType(Number value, NumberTypeID id) const;

	void Search(const NumberQuery& query, Numbers& outNumbers) const;

	Number GetNth(NumberSequenceType type, Index index) const;
	std::optional<Index> GetIndex(NumberSequenceType type, Number value) const;

	bool Holds(NumberRelationshipType type, Number left, Number right) const;

private:
	void RegisterBuiltInTypes();

private:
	NumberCache mCache;
	BuiltInNumbers mBuiltIns;
	NumberTypeRegistry mTypeRegistry;
	NumberSequenceRegistry mSequenceRegistry;
	NumberRelationshipRegistry mRelationshipRegistry;
};

} // namespace MY

#endif // MY_NUMBER_CLASSIFIER_H
