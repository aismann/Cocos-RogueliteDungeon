#ifndef __CHARACTER_STATS_H__
#define __CHARACTER_STATS_H__
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>
#include <typeinfo>
#include "cocos2d.h"
#include "Entity.h"

class Entity;
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
	Entity* Source;
public:
	StatModifier(float value, StatModifierType type, int order, Entity* source);
	StatModifier(float value, StatModifierType type);
	StatModifier(float value, StatModifierType type, int order);
	StatModifier(float value, StatModifierType type, Entity* source);
	~StatModifier() {}
	float getValue();
	StatModifierType getType();
	int getOrder();
	Entity* getSource();
};
#pragma endregion

#pragma region EntityStats
class EntityStats
{
protected:
	bool isDirty = true;
	float baseValue;
	float _value;
	float lastBaseValue = std::numeric_limits<float>::min();
	std::vector<StatModifier*> statModifier;
	std::vector<StatModifier*>::iterator it;
public:
	EntityStats();
	~EntityStats();
	const std::vector<StatModifier*> getReadOnlyStatModifier();
	void addModifier(StatModifier* statmodify);
	bool removeModifier(StatModifier* statmodify);
	bool removeAllModifier(Entity* source);
	float getValue();
private:
	float calculateStatValue();
	int compareModifierOrder(StatModifier* modA, StatModifier* modB);
};
#pragma endregion

#endif // !__CHARACTER_STATS_H__