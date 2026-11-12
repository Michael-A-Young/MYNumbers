/**
@file
	Maths.cpp
@brief
	Shared mathematical functions used by number classification.
*/

#include "Maths.h"

// Standard Library
#include <algorithm>

namespace MY
{

void GetDivisors(Number value, Numbers& outDivisors)
{
	GetProperDivisors(value, outDivisors);

	if (value != 0)
	{
		outDivisors.push_back(value);
	}
}

void GetProperDivisors(Number value, Numbers& outProperDivisors)
{
	outProperDivisors.clear();

	if (value > 1)
	{
		outProperDivisors.push_back(1);

		for (Number divisor = 2; divisor <= value / divisor; ++divisor)
		{
			if (value % divisor == 0)
			{
				const Number pairedDivisor = value / divisor;
				outProperDivisors.push_back(divisor);

				if (pairedDivisor != divisor)
				{
					outProperDivisors.push_back(pairedDivisor);
				}
			}
		}

		std::sort(outProperDivisors.begin(), outProperDivisors.end());
	}
}

void GetPrimeDivisors(Number value, Numbers& outPrimeDivisors)
{
	outPrimeDivisors.clear();

	Number remaining = value;

	for (Number divisor = 2; divisor <= remaining / divisor; ++divisor)
	{
		if (remaining % divisor == 0)
		{
			outPrimeDivisors.push_back(divisor);

			while (remaining % divisor == 0)
			{
				remaining /= divisor;
			}
		}
	}

	if (remaining > 1)
	{
		outPrimeDivisors.push_back(remaining);
	}
}

void GetDigits(Number value, Digits& outDigits)
{
	outDigits.clear();

	do
	{
		outDigits.push_back(static_cast<Digit>(value % 10));
		value /= 10;
	} while (value != 0);

	std::reverse(outDigits.begin(), outDigits.end());
}

Number GetDigitSum(Number value)
{
	Number result = 0;

	while (value != 0)
	{
		result += value % 10;
		value /= 10;
	}

	return result;
}

Number GetGCD(Number left, Number right)
{
	while (right != 0)
	{
		const Number remainder = left % right;
		left = right;
		right = remainder;
	}

	return left;
}

Number GetLCM(Number left, Number right)
{
	Number result = 0;

	if (left != 0 && right != 0)
	{
		result = (left / GetGCD(left, right)) * right;
	}

	return result;
}

Number GetIntegerSquareRoot(Number value)
{
	Number result = 0;
	Number low = 0;
	Number high = value;

	while (low <= high)
	{
		const Number middle = low + (high - low) / 2;

		if (middle == 0 || middle <= value / middle)
		{
			result = middle;
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}

	return result;
}

Number ReverseDigits(Number value)
{
	Number result = 0;

	while (value != 0)
	{
		result = result * 10 + value % 10;
		value /= 10;
	}

	return result;
}

} // namespace MY
