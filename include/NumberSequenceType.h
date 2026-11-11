/**
@file
	NumberSequenceType.h
@brief
	Stable identifiers for every built-in number sequence.
*/

#ifndef MY_NUMBER_SEQUENCE_TYPE_H
#define MY_NUMBER_SEQUENCE_TYPE_H

// Standard Library
#include <cstdint>
#include <vector>

namespace MY
{

enum class NumberSequenceType : uint32_t
{
	Invalid = 0,
	BuiltInCount,
	FirstCustom = BuiltInCount
};

using NumberSequenceTypes = std::vector<NumberSequenceType>;

} // namespace MY

#endif // MY_NUMBER_SEQUENCE_TYPE_H
