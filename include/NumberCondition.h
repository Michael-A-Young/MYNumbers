/**
@file
	NumberCondition.h
@brief
	A composable condition over a single number.
*/

#ifndef MY_NUMBER_CONDITION_H
#define MY_NUMBER_CONDITION_H

// MYNumbers
#include "Number.h"
#include "NumberRelationshipType.h"
#include "NumberTypeID.h"

// Standard Library
#include <vector>

namespace MY
{

class NumberClassifier;

class NumberCondition
{
public:
	static NumberCondition Type(NumberTypeID typeID);
	static NumberCondition RelatesTo(NumberRelationshipType type, Number operand);
	static NumberCondition RelatesFrom(NumberRelationshipType type, Number operand);

	static NumberCondition Not(NumberCondition condition);
	static NumberCondition All(std::vector<NumberCondition> conditions);
	static NumberCondition Any(std::vector<NumberCondition> conditions);

	bool Matches(Number value, const NumberClassifier& classifier) const;

private:
	enum class Kind
	{
		Type,
		RelatesTo,
		RelatesFrom,
		Not,
		All,
		Any
	};

	NumberCondition(Kind kind);

private:
	Kind mKind;
	NumberTypeID mType;
	NumberRelationshipType mRelationshipType;
	Number mOperand;
	std::vector<NumberCondition> mChildren;
};

} // namespace MY

#endif // MY_NUMBER_CONDITION_H
