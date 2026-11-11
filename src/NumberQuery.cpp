/**
@file
	NumberQuery.cpp
@brief
	A set of conditions and ranges describing numbers of interest.
*/

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
