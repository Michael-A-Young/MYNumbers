/**
@file
	NumberContext.cpp
@brief
	A number paired with access to shared cached results.
*/

#include "NumberContext.h"

// MYNumbers
#include "NumberCache.h"

namespace MY
{

NumberContext::NumberContext(Number value, const NumberCache& cache)
	: mValue(value)
	, mCache(&cache)
{
}

Number NumberContext::GetValue() const
{
	return mValue;
}

NumberContext::operator Number() const
{
	return GetValue();
}

const Numbers& NumberContext::GetPrimeDivisors() const
{
	return mCache->GetPrimeDivisors(mValue);
}

const Numbers& NumberContext::GetDivisors() const
{
	return mCache->GetDivisors(mValue);
}

Number NumberContext::GetDivisorCount() const
{
	return mCache->GetDivisorCount(mValue);
}

Number NumberContext::GetDivisorSum() const
{
	return mCache->GetDivisorSum(mValue);
}

Number NumberContext::GetProperDivisorSum() const
{
	return mCache->GetProperDivisorSum(mValue);
}

bool NumberContext::IsPrime() const
{
	return mCache->IsPrime(mValue);
}

} // namespace MY
