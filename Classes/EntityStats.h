#ifndef __ENTITY_STATS_H__
#define __ENTITY_STATS_H__
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>
#include <typeinfo>
#include "cocos2d.h"
#include "StatModifier.h"

class Entity;
class StatModifier;
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