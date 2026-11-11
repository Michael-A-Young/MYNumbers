/**
@file
	NumberTypeRegistry.h
@brief
	Stores and retrieves number types by identifier.
*/

#ifndef MY_NUMBER_TYPE_REGISTRY_H
#define MY_NUMBER_TYPE_REGISTRY_H

// MYNumbers
#include "NumberType.h"
#include "NumberTypeID.h"

// Standard Library
#include <cstddef>
#include <unordered_map>

namespace MY
{

class NumberTypeRegistry
{
public:
	NumberTypeRegistry();

	NumberTypeRegistry(const NumberTypeRegistry& other) = default;
	NumberTypeRegistry(NumberTypeRegistry&& other) = default;

	NumberTypeRegistry& operator=(const NumberTypeRegistry& other) = default;
	NumberTypeRegistry& operator=(NumberTypeRegistry&& other) = default;

	~NumberTypeRegistry() = default;

public:
	NumberTypeID Register(NumberType& type);
	bool Register(NumberType& type, NumberTypeID id);

	const NumberType* Get(NumberTypeID id) const;
	void GetIDs(NumberTypeIDs& outIDs) const;

	size_t NumTypes() const;

private:
	std::unordered_map<NumberTypeID, NumberType*> mTypes;
	NumberTypeID mNextCustomID;
};

} // namespace MY

#endif // MY_NUMBER_TYPE_REGISTRY_H
