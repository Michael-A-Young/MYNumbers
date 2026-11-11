#include "BuiltInNumbers.h"

namespace MY
{

BuiltInNumbers::BuiltInNumbers()
	: mTypes()
	, mSequences()
	, mRelationships()
{
}

void BuiltInNumbers::RegisterTypes(NumberTypeRegistry* /* registry */)
{
}

void BuiltInNumbers::RegisterSequences(NumberSequenceRegistry* /* registry */)
{
}

void BuiltInNumbers::RegisterRelationships(NumberRelationshipRegistry* /* registry */)
{
}

} // namespace MY
