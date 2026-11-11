#include "BuiltInNumbers.h"

namespace MY
{

BuiltInNumbers::BuiltInNumbers()
	: mTypes()
	, mSequences()
	, mRelationships()
{
}

void BuiltInNumbers::RegisterTypes(TypeRegistry<NumberType>* /* registry */)
{
}

void BuiltInNumbers::RegisterSequences(TypeRegistry<NumberSequence>* /* registry */)
{
}

void BuiltInNumbers::RegisterRelationships(TypeRegistry<NumberRelationship>* /* registry */)
{
}

} // namespace MY
