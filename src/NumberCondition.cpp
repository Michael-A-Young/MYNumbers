#include "NumberCondition.h"

namespace MY
{

NumberCondition::NumberCondition(Kind kind)
	: mKind(kind)
	, mType(NumberTypeID::Invalid)
	, mRelationshipType(NumberRelationshipType::Invalid)
	, mOperand(0)
	, mChildren()
{
}

} // namespace MY
