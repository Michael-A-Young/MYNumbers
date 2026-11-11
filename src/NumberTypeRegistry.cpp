#include "NumberTypeRegistry.h"

namespace MY
{

NumberTypeRegistry::NumberTypeRegistry()
	: mTypes()
	, mNextCustomID(NumberTypeID::FirstCustom)
{
}

} // namespace MY
