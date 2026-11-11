/**
@file
	NumberRelationshipRegistry.h
@brief
	Stores and retrieves number relationships by identifier.
*/

#ifndef MY_NUMBER_RELATIONSHIP_REGISTRY_H
#define MY_NUMBER_RELATIONSHIP_REGISTRY_H

// MYNumbers
#include "NumberRelationship.h"
#include "NumberRelationshipType.h"

// Standard Library
#include <cstddef>
#include <unordered_map>

namespace MY
{

class NumberRelationshipRegistry
{
public:
	NumberRelationshipRegistry();

	NumberRelationshipRegistry(const NumberRelationshipRegistry& other) = default;
	NumberRelationshipRegistry(NumberRelationshipRegistry&& other) = default;

	NumberRelationshipRegistry& operator=(const NumberRelationshipRegistry& other) = default;
	NumberRelationshipRegistry& operator=(NumberRelationshipRegistry&& other) = default;

	~NumberRelationshipRegistry() = default;

public:
	NumberRelationshipType Register(NumberRelationship& relationship);
	bool Register(NumberRelationship& relationship, NumberRelationshipType type);

	const NumberRelationship* Get(NumberRelationshipType type) const;

	size_t NumRelationships() const;

private:
	std::unordered_map<NumberRelationshipType, NumberRelationship*> mRelationships;
	NumberRelationshipType mNextCustomType;
};

} // namespace MY

#endif // MY_NUMBER_RELATIONSHIP_REGISTRY_H
