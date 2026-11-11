#include "NumberSequence.h"

namespace MY
{

NumberSequence::NumberSequence()
{
}

bool NumberSequence::Contains(Number value) const
{
	return GetIndex(value).has_value();
}

} // namespace MY
