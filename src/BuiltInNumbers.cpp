/**
@file
	BuiltInNumbers.cpp
@brief
	Owns the built-in number types, sequences and relationships.
*/

#include "BuiltInNumbers.h"

namespace MY
{

BuiltInNumbers::BuiltInNumbers()
	: mTypes(GetTypes())
	, mSequences(GetSequences())
	, mRelationships(GetRelationships())
{
}

void BuiltInNumbers::RegisterTypes(TypeRegistry<NumberType>* registry)
{
	for (std::unique_ptr<NumberType>& type : mTypes)
	{
		registry->Register(*type);
	}
}

void BuiltInNumbers::RegisterSequences(TypeRegistry<NumberSequence>* registry)
{
	for (std::unique_ptr<NumberSequence>& sequence : mSequences)
	{
		registry->Register(*sequence);
	}
}

void BuiltInNumbers::RegisterRelationships(TypeRegistry<NumberRelationship>* registry)
{
	for (std::unique_ptr<NumberRelationship>& relationship : mRelationships)
	{
		registry->Register(*relationship);
	}
}

std::vector<std::unique_ptr<NumberType>> BuiltInNumbers::GetTypes()
{
	std::vector<std::unique_ptr<NumberType>> types;
	return types;
}

std::vector<std::unique_ptr<NumberSequence>> BuiltInNumbers::GetSequences()
{
	std::vector<std::unique_ptr<NumberSequence>> sequences;
	return sequences;
}

std::vector<std::unique_ptr<NumberRelationship>> BuiltInNumbers::GetRelationships()
{
	std::vector<std::unique_ptr<NumberRelationship>> relationships;
	return relationships;
}

} // namespace MY
