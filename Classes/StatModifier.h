#ifndef __STAT_MODIFIER_H__
#define __STAT_MODIFIER_H__
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
#endif