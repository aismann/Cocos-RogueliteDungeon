#ifndef __CHARACTER_STATS_H__
#define __CHARACTER_STATS_H__
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>
#include "cocos2d.h"

#pragma region StatModifier
enum class StatModifierType
{
	Flat = 100,
	PercentAdd = 200,
	PercentMult = 300
};
class StatModifier
{
private:
	float Value;
	StatModifierType Type;
	int Order;
	cocos2d::Sprite* Source;
public:
	StatModifier(float value, StatModifierType type, int order, cocos2d::Sprite* source);
	~StatModifier() {}
	float getValue();
	StatModifierType getType();
	int getOrder();
	cocos2d::Sprite* getSource();
};
#pragma endregion

#pragma region EntityStats
class EntityStats
{
protected:
	bool isDirty = true;
	float _value;
	float lastBaseValue = std::numeric_limits<float>::min();
	std::vector<StatModifier> statModifier;
public:
	float baseValue;
	EntityStats();
	~EntityStats();
	const std::vector<StatModifier> getReadOnlyStatModifier();
	void addModifier(StatModifier& statmodify);
	bool removeModifier(StatModifier& statmodify);
	bool removeAllModifier(cocos2d::Sprite* source);
	float getValue();
private:
	float calculateStatValue();
	int compareModifierOrder(StatModifier& modA, StatModifier& modB);
};
#pragma endregion

#endif // !__CHARACTER_STATS_H__