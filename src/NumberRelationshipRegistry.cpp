#include "NumberRelationshipRegistry.h"

namespace MY
{

NumberRelationshipRegistry::NumberRelationshipRegistry()
	: mRelationships()
	, mNextCustomType(NumberRelationshipType::FirstCustom)
{
}

} // namespace MY
