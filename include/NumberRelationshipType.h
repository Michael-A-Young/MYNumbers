/**
@file
	NumberRelationshipType.h
@brief
	Stable identifiers for every built-in number relationship.
*/

#ifndef MY_NUMBER_RELATIONSHIP_TYPE_H
#define MY_NUMBER_RELATIONSHIP_TYPE_H

// Standard Library
#include <cstdint>
#include <vector>

namespace MY
{

enum class NumberRelationshipType : uint32_t
{
	Invalid = 0,
	BuiltInCount,
	FirstCustom = BuiltInCount
};

using NumberRelationshipTypes = std::vector<NumberRelationshipType>;

} // namespace MY

#endif // MY_NUMBER_RELATIONSHIP_TYPE_H
