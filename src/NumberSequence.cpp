/**
@file
	NumberSequence.cpp
@brief
	Interface for number types that form an ordered sequence.
*/

#include "NumberSequence.h"

namespace MY
{

NumberSequence::NumberSequence()
{
}

bool NumberSequence::Contains(Number value) const
{
	return GetIndex(value).has_value();
}

} // namespace MY
