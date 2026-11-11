/**
@file
	NumberTypeID.h
@brief
	Stable identifiers for every built-in number type.
*/

#ifndef MY_NUMBER_TYPE_ID_H
#define MY_NUMBER_TYPE_ID_H

// Standard Library
#include <cstdint>
#include <vector>

namespace MY
{

enum class NumberTypeID : uint32_t
{
	Invalid = 0,
	BuiltInCount,
	FirstCustom = BuiltInCount
};

using NumberTypeIDs = std::vector<NumberTypeID>;

} // namespace MY

#endif // MY_NUMBER_TYPE_ID_H
