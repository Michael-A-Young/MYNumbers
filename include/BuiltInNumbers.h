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
#include "NumberRelationshipType.h"
#include "NumberSequence.h"
#include "NumberSequenceType.h"
#include "NumberType.h"
#include "NumberTypeID.h"

// Standard Library
#include <map>
#include <memory>

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
	static std::map<NumberTypeID, std::unique_ptr<NumberType>> GetTypes();
	static std::map<NumberSequenceType, std::unique_ptr<NumberSequence>> GetSequences();
	static std::map<NumberRelationshipType, std::unique_ptr<NumberRelationship>> GetRelationships();

private:
	std::map<NumberTypeID, std::unique_ptr<NumberType>> mTypes;
	std::map<NumberSequenceType, std::unique_ptr<NumberSequence>> mSequences;
	std::map<NumberRelationshipType, std::unique_ptr<NumberRelationship>> mRelationships;
};

} // namespace MY

#endif // MY_BUILT_IN_NUMBERS_H
