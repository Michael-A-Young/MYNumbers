/**
@file
	BuiltInNumbers.h
@brief
	Owns the built-in number types, sequences and relationships.
*/

#ifndef MY_BUILT_IN_NUMBERS_H
#define MY_BUILT_IN_NUMBERS_H

// MYNumbers
#include "TypeRegistry.h"
#include "NumberRelationship.h"
#include "NumberSequence.h"
#include "NumberType.h"

// Standard Library
#include <memory>
#include <vector>

namespace MY
{

class BuiltInNumbers
{
public:
	BuiltInNumbers();

	BuiltInNumbers(const BuiltInNumbers& other) = delete;
	BuiltInNumbers(BuiltInNumbers&& other) = default;

	BuiltInNumbers& operator=(const BuiltInNumbers& other) = delete;
	BuiltInNumbers& operator=(BuiltInNumbers&& other) = default;

	~BuiltInNumbers() = default;

public:
	void RegisterTypes(TypeRegistry<NumberType>* registry);
	void RegisterSequences(TypeRegistry<NumberSequence>* registry);
	void RegisterRelationships(TypeRegistry<NumberRelationship>* registry);

private:
	std::vector<std::unique_ptr<NumberType>> mTypes;
	std::vector<std::unique_ptr<NumberSequence>> mSequences;
	std::vector<std::unique_ptr<NumberRelationship>> mRelationships;
};

} // namespace MY

#endif // MY_BUILT_IN_NUMBERS_H
