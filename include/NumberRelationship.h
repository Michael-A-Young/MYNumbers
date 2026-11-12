/**
@file
	NumberRelationship.h
@brief
	Interface for a relationship between two numbers.

	Relationships are not necessarily symmetric: Holds(left, right) may differ
	from Holds(right, left).
*/

#ifndef MY_NUMBER_RELATIONSHIP_H
#define MY_NUMBER_RELATIONSHIP_H

// MYNumbers
#include "Number.h"
#include "NumberContext.h"

// Standard Library
#include <string_view>

namespace MY
{

class NumberRelationship
{
public:
	NumberRelationship();

	NumberRelationship(const NumberRelationship& other) = default;
	NumberRelationship(NumberRelationship&& other) = default;

	NumberRelationship& operator=(const NumberRelationship& other) = default;
	NumberRelationship& operator=(NumberRelationship&& other) = default;

	virtual ~NumberRelationship() = default;

public:
	virtual std::string_view GetName() const = 0;
	virtual bool Holds(NumberContext left, NumberContext right) const = 0;

};

} // namespace MY

#endif // MY_NUMBER_RELATIONSHIP_H
