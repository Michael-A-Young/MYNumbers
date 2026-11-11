/**
@file
	Number.h
@brief
	The scalar types used throughout the library.
*/

#ifndef MY_NUMBER_H
#define MY_NUMBER_H

// Standard Library
#include <cstddef>
#include <cstdint>
#include <vector>

namespace MY
{

using Number = uint64_t;
using Index = size_t;
using Digit = uint8_t;

using Numbers = std::vector<Number>;
using Digits = std::vector<Digit>;

} // namespace MY

#endif // MY_NUMBER_H
