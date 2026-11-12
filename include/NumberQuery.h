/**
@file
	NumberQuery.h
@brief
	A set of conditions and ranges describing numbers of interest.
*/

#ifndef MY_NUMBER_QUERY_H
#define MY_NUMBER_QUERY_H

// MYNumbers
#include "Number.h"
#include "NumberClassifier.h"
#include "NumberCondition.h"

// Standard Library
#include <chrono>
#include <optional>

namespace MY
{

struct NumberRange
{
	Number first;
	Number last;
};

using NumberRanges = std::vector<NumberRange>;

class NumberQuery
{
public:
	explicit NumberQuery(const NumberClassifier& classifier);

	NumberQuery(const NumberQuery& other) = default;
	NumberQuery(NumberQuery&& other) = default;

	NumberQuery& operator=(const NumberQuery& other) = default;
	NumberQuery& operator=(NumberQuery&& other) = default;

	~NumberQuery() = default;

public:
	NumberQuery& Where(NumberCondition condition);
	NumberQuery& Range(Number first, Number last);

	NumberQuery& SetMaxResults(size_t maxResults);
	NumberQuery& SetMaxTime(std::chrono::milliseconds maxTime);

	bool Matches(Number value) const;

	const NumberRanges& GetRanges() const;
	std::optional<size_t> GetMaxResults() const;
	std::optional<std::chrono::milliseconds> GetMaxTime() const;

private:
	void NormaliseRange();

private:
	const NumberClassifier* mClassifier;
	std::vector<NumberCondition> mConditions;
	NumberRanges mRanges;
	std::optional<size_t> mMaxResults;
	std::optional<std::chrono::milliseconds> mMaxTime;
};

} // namespace MY

#endif // MY_NUMBER_QUERY_H
