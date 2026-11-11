/**
@file
	NumberCache.h
@brief
	Caches per-number results shared between classifiers.
*/

#ifndef MY_NUMBER_CACHE_H
#define MY_NUMBER_CACHE_H

// MYNumbers
#include "Number.h"

// Standard Library
#include <unordered_map>

namespace MY
{

class NumberCache
{
public:
	NumberCache();

	NumberCache(const NumberCache& other) = default;
	NumberCache(NumberCache&& other) = default;

	NumberCache& operator=(const NumberCache& other) = default;
	NumberCache& operator=(NumberCache&& other) = default;

	~NumberCache() = default;

public:
	const Numbers& GetPrimeDivisors(Number value) const;
	const Numbers& GetDivisors(Number value) const;

	Number GetDivisorCount(Number value) const;
	Number GetDivisorSum(Number value) const;
	Number GetProperDivisorSum(Number value) const;
	bool IsPrime(Number value) const;

	void Clear();
	size_t NumNumbers() const;

private:
	mutable std::unordered_map<Number, Numbers> mPrimeDivisors;
	mutable std::unordered_map<Number, Numbers> mDivisors;
};

} // namespace MY

#endif // MY_NUMBER_CACHE_H
