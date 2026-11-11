/**
@file
	NumberSequenceRegistry.h
@brief
	Stores and retrieves number sequences by identifier.
*/

#ifndef MY_NUMBER_SEQUENCE_REGISTRY_H
#define MY_NUMBER_SEQUENCE_REGISTRY_H

// MYNumbers
#include "NumberSequence.h"
#include "NumberSequenceType.h"

// Standard Library
#include <cstddef>
#include <unordered_map>

namespace MY
{

class NumberSequenceRegistry
{
public:
	NumberSequenceRegistry();

	NumberSequenceRegistry(const NumberSequenceRegistry& other) = default;
	NumberSequenceRegistry(NumberSequenceRegistry&& other) = default;

	NumberSequenceRegistry& operator=(const NumberSequenceRegistry& other) = default;
	NumberSequenceRegistry& operator=(NumberSequenceRegistry&& other) = default;

	~NumberSequenceRegistry() = default;

public:
	NumberSequenceType Register(NumberSequence& sequence);
	bool Register(NumberSequence& sequence, NumberSequenceType type);

	const NumberSequence* Get(NumberSequenceType type) const;

	size_t NumSequences() const;

private:
	std::unordered_map<NumberSequenceType, NumberSequence*> mSequences;
	NumberSequenceType mNextCustomType;
};

} // namespace MY

#endif // MY_NUMBER_SEQUENCE_REGISTRY_H
