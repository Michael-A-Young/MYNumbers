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
	for (const auto& entry : mTypes)
	{
		registry->Register(*entry.second, static_cast<uint32_t>(entry.first));
	}
}

void BuiltInNumbers::RegisterSequences(TypeRegistry<NumberSequence>* registry)
{
	for (const auto& entry : mSequences)
	{
		registry->Register(*entry.second, static_cast<uint32_t>(entry.first));
	}
}

void BuiltInNumbers::RegisterRelationships(TypeRegistry<NumberRelationship>* registry)
{
	for (const auto& entry : mRelationships)
	{
		registry->Register(*entry.second, static_cast<uint32_t>(entry.first));
	}
}

std::map<NumberTypeID, std::unique_ptr<NumberType>> BuiltInNumbers::GetTypes()
{
	std::map<NumberTypeID, std::unique_ptr<NumberType>> types;
	return types;
}

std::map<NumberSequenceType, std::unique_ptr<NumberSequence>> BuiltInNumbers::GetSequences()
{
	std::map<NumberSequenceType, std::unique_ptr<NumberSequence>> sequences;
	return sequences;
}

std::map<NumberRelationshipType, std::unique_ptr<NumberRelationship>> BuiltInNumbers::GetRelationships()
{
	std::map<NumberRelationshipType, std::unique_ptr<NumberRelationship>> relationships;
	return relationships;
}

} // namespace MY
