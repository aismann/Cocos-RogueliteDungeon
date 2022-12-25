#include "StatModifier.h"
USING_NS_CC;

StatModifier::StatModifier(float value, StatModifierType type, int order, Entity* source):Value(value),Type(type),Order(order),Source(source)
{
}

StatModifier::StatModifier(float value, StatModifierType type):Value(value),Type(type),Order((int)type),Source(nullptr)
{
}

StatModifier::StatModifier(float value, StatModifierType type, int order):Value(value), Type(type), Order(order), Source(nullptr)
{
}

StatModifier::StatModifier(float value, StatModifierType type, Entity* source) :Value(value), Type(type), Order((int)type), Source(source)
{
}

float StatModifier::getValue()
{
	return this->Value;
}

StatModifierType StatModifier::getType()
{
	return this->Type;
}

int StatModifier::getOrder()
{
	return this->Order;
}

Entity* StatModifier::getSource()
{
	return this->Source;
}
