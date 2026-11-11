/**
@file
	NumberType.h
@brief
	Interface for a classification of numbers.
*/

#ifndef MY_NUMBER_TYPE_H
#define MY_NUMBER_TYPE_H

// MYNumbers
#include "Number.h"

// Standard Library
#include <string_view>

namespace MY
{

class NumberType
{
public:
	NumberType();

	NumberType(const NumberType& other) = default;
	NumberType(NumberType&& other) = default;

	NumberType& operator=(const NumberType& other) = default;
	NumberType& operator=(NumberType&& other) = default;

	virtual ~NumberType() = default;

public:
	virtual std::string_view GetName() const = 0;
	virtual bool IsMember(Number value) const = 0;

};

} // namespace MY

#endif // MY_NUMBER_TYPE_H
