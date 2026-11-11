/**
@file
	Maths.h
@brief
	Shared mathematical functions used by number classification.
*/

#ifndef MY_MATHS_H
#define MY_MATHS_H

// MYNumbers
#include "Number.h"

namespace MY
{

void GetDivisors(Number value, Numbers& outDivisors);
void GetProperDivisors(Number value, Numbers& outProperDivisors);
void GetPrimeDivisors(Number value, Numbers& outPrimeDivisors);
void GetDigits(Number value, Digits& outDigits);

Number GetDigitSum(Number value);
Number GetGCD(Number left, Number right);
Number GetLCM(Number left, Number right);
Number GetIntegerSquareRoot(Number value);
Number ReverseDigits(Number value);

} // namespace MY

#endif // MY_MATHS_H
