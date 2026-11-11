#include "NumberClassifier.h"

namespace MY
{

NumberClassifier::NumberClassifier()
	: mCache()
	, mBuiltIns()
	, mTypeRegistry(static_cast<uint32_t>(NumberTypeID::FirstCustom))
	, mSequenceRegistry(static_cast<uint32_t>(NumberSequenceType::FirstCustom))
	, mRelationshipRegistry(static_cast<uint32_t>(NumberRelationshipType::FirstCustom))
{
	RegisterBuiltInTypes();
}

void NumberClassifier::RegisterBuiltInTypes()
{
	mBuiltIns.RegisterTypes(&mTypeRegistry);
	mBuiltIns.RegisterSequences(&mSequenceRegistry);
	mBuiltIns.RegisterRelationships(&mRelationshipRegistry);
}

} // namespace MY
