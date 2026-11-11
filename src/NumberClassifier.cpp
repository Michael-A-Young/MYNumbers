#include "NumberClassifier.h"

namespace MY
{

NumberClassifier::NumberClassifier()
	: mCache()
	, mBuiltIns()
	, mTypeRegistry()
	, mSequenceRegistry()
	, mRelationshipRegistry()
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
