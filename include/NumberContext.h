/**
@file
	NumberContext.h
@brief
	A number paired with access to shared cached results.

	The cache is only guaranteed to outlive the context's immediate use.
*/

#ifndef MY_NUMBER_CONTEXT_H
#define MY_NUMBER_CONTEXT_H

// MYNumbers
#include "Number.h"

namespace MY
{

class NumberCache;

class NumberContext
{
public:
	NumberContext(Number value, const NumberCache& cache);

	NumberContext(const NumberContext& other) = default;
	NumberContext(NumberContext&& other) = default;

	NumberContext& operator=(const NumberContext& other) = default;
	NumberContext& operator=(NumberContext&& other) = default;

	~NumberContext() = default;

public:
	Number GetValue() const;
	operator Number() const;

	const Numbers& GetPrimeDivisors() const;
	const Numbers& GetDivisors() const;

	Number GetDivisorCount() const;
	Number GetDivisorSum() const;
	Number GetProperDivisorSum() const;
	bool IsPrime() const;

private:
	Number mValue;
	const NumberCache* mCache;
};

} // namespace MY

#endif // MY_NUMBER_CONTEXT_H
