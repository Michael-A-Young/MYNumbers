/**
@file
	Math.h
@brief
	Shared mathematical functions used by number classification.
*/

#ifndef MY_MATH_H
#define MY_MATH_H

// MYNumbers
#include "Number.h"

namespace MY
{

void GetDivisors(Number value, Numbers& outDivisors);
void GetProperDivisors(Number value, Numbers& outProperDivisors);
void GetPrimeDivisors(Number value, Numbers& outPrimeDivisors);
void GetDigits(Number value, Digits& outDigits);

Number GetDivisorCount(Number value);
Number GetDivisorSum(Number value);
Number GetProperDivisorSum(Number value);
Number GetDigitSum(Number value);
Number GetGcd(Number left, Number right);
Number GetLcm(Number left, Number right);
Number GetIntegerSquareRoot(Number value);
Number ReverseDigits(Number value);

} // namespace MY

#endif // MY_MATH_H
