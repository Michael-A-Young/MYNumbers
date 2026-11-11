#include "NumberQuery.h"

namespace MY
{

NumberQuery::NumberQuery(const NumberClassifier& classifier)
	: mClassifier(&classifier)
	, mConditions()
	, mRanges()
	, mMaxResults()
	, mMaxTime()
{
}

} // namespace MY
