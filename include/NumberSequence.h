/**
@file
	NumberSequence.h
@brief
	Interface for number types that form an ordered sequence.
*/

#ifndef MY_NUMBER_SEQUENCE_H
#define MY_NUMBER_SEQUENCE_H

// MYNumbers
#include "Number.h"

// Standard Library
#include <optional>

namespace MY
{

class NumberSequence
{
public:
	NumberSequence();

	NumberSequence(const NumberSequence& other) = default;
	NumberSequence(NumberSequence&& other) = default;

	NumberSequence& operator=(const NumberSequence& other) = default;
	NumberSequence& operator=(NumberSequence&& other) = default;

	virtual ~NumberSequence() = default;

public:
	virtual Number GetNth(Index index) const = 0;
	virtual std::optional<Index> GetIndex(Number value) const = 0;

	virtual bool Contains(Number value) const;

};

} // namespace MY

#endif // MY_NUMBER_SEQUENCE_H
