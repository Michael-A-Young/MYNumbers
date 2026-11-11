/**
@file
	TypeRegistry.h
@brief
	Stores and retrieves resources by registered identifier.
*/

#ifndef MY_TYPE_REGISTRY_H
#define MY_TYPE_REGISTRY_H

// Standard Library
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace MY
{

template <typename Resource>
class TypeRegistry
{
public:
	explicit TypeRegistry(uint32_t firstCustomID);

	TypeRegistry(const TypeRegistry& other) = default;
	TypeRegistry(TypeRegistry&& other) = default;

	TypeRegistry& operator=(const TypeRegistry& other) = default;
	TypeRegistry& operator=(TypeRegistry&& other) = default;

	~TypeRegistry() = default;

public:
	uint32_t Register(Resource& resource);
	bool Register(Resource& resource, uint32_t typeID);

	const Resource* Get(uint32_t typeID) const;
	void GetIDs(std::vector<uint32_t>& outIDs) const;

	size_t Num() const;

private:
	void FindNextCustomID();

private:
	std::unordered_map<uint32_t, Resource*> mResources;
	uint32_t mFirstCustomID;
	uint32_t mNextCustomID;
};

} // namespace MY

#include "TypeRegistry.inl"

#endif // MY_TYPE_REGISTRY_H
