/**
@file
	NumberQuery.cpp
@brief
	A set of conditions and ranges describing numbers of interest.
*/

// MYNumbers
#include "NumberQuery.h"

// Standard Library
#include <algorithm>
#include <limits>
#include <utility>

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

NumberQuery& NumberQuery::Where(NumberCondition condition)
{
	mConditions.push_back(std::move(condition));
	return *this;
}

NumberQuery& NumberQuery::Range(Number first, Number last)
{
	if (first > last)
	{
		std::swap(first, last);
	}

	mRanges.push_back(NumberRange{first, last});
	NormaliseRange();
	return *this;
}

void NumberQuery::NormaliseRange()
{
	std::sort(mRanges.begin(), mRanges.end(), [](const NumberRange& left, const NumberRange& right)
	{
		return left.first < right.first;
	});

	NumberRanges normalisedRanges;
	normalisedRanges.reserve(mRanges.size());

	for (const NumberRange& range : mRanges)
	{
		if (normalisedRanges.empty())
		{
			normalisedRanges.push_back(range);
		}
		else
		{
			NumberRange& current = normalisedRanges.back();
			const bool overlaps = range.first <= current.last;
			const bool adjacent = current.last != std::numeric_limits<Number>::max() && range.first == current.last + 1;

			if (overlaps || adjacent)
			{
				if (range.last > current.last)
				{
					current.last = range.last;
				}
			}
			else
			{
				normalisedRanges.push_back(range);
			}
		}
	}

	mRanges.swap(normalisedRanges);
}

NumberQuery& NumberQuery::SetMaxResults(size_t maxResults)
{
	mMaxResults = maxResults;
	return *this;
}

NumberQuery& NumberQuery::SetMaxTime(std::chrono::milliseconds maxTime)
{
	mMaxTime = maxTime;
	return *this;
}

bool NumberQuery::Matches(Number value) const
{
	bool inRange = mRanges.empty();

	for (const NumberRange& range : mRanges)
	{
		if (value >= range.first && value <= range.last)
		{
			inRange = true;
		}
	}

	bool matchesConditions = true;

	if (inRange)
	{
		for (const NumberCondition& condition : mConditions)
		{
			if (!condition.Matches(value, *mClassifier))
			{
				matchesConditions = false;
			}
		}
	}

	return inRange && matchesConditions;
}

const NumberRanges& NumberQuery::GetRanges() const
{
	return mRanges;
}

std::optional<size_t> NumberQuery::GetMaxResults() const
{
	return mMaxResults;
}

std::optional<std::chrono::milliseconds> NumberQuery::GetMaxTime() const
{
	return mMaxTime;
}

} // namespace MY
