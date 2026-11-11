/**
@file
	NumberCache.cpp
@brief
	Caches per-number results shared between classifiers.
*/

// MYNumbers
#include "NumberCache.h"
#include "Maths.h"

namespace MY
{

NumberCache::NumberCache()
	: mPrimeDivisors()
	, mDivisors()
{
}

const Numbers& NumberCache::GetPrimeDivisors(Number value) const
{
	const Numbers* result = nullptr;
	auto it = mPrimeDivisors.find(value);

	if (it != mPrimeDivisors.end())
	{
		result = &it->second;
	}
	else
	{
		it = mPrimeDivisors.emplace(value, Numbers()).first;
		MY::GetPrimeDivisors(value, it->second);
		result = &it->second;
	}

	return *result;
}

const Numbers& NumberCache::GetDivisors(Number value) const
{
	const Numbers* result = nullptr;
	auto it = mDivisors.find(value);

	if (it != mDivisors.end())
	{
		result = &it->second;
	}
	else
	{
		it = mDivisors.emplace(value, Numbers()).first;
		MY::GetDivisors(value, it->second);
		result = &it->second;
	}

	return *result;
}

Number NumberCache::GetDivisorCount(Number value) const
{
	return static_cast<Number>(GetDivisors(value).size());
}

Number NumberCache::GetDivisorSum(Number value) const
{
	Number result = 0;

	for (const Number divisor : GetDivisors(value))
	{
		result += divisor;
	}

	return result;
}

Number NumberCache::GetProperDivisorSum(Number value) const
{
	Number result = 0;

	for (const Number divisor : GetDivisors(value))
	{
		if (divisor != value)
		{
			result += divisor;
		}
	}

	return result;
}

bool NumberCache::IsPrime(Number value) const
{
	const Numbers& primeDivisors = GetPrimeDivisors(value);
	return value > 1 && primeDivisors.size() == 1 && primeDivisors.front() == value;
}

void NumberCache::Clear()
{
	mPrimeDivisors.clear();
	mDivisors.clear();
}

} // namespace MY
