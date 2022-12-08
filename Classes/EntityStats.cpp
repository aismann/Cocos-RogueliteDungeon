#include "EntityStats.h"
USING_NS_CC;
StatModifier::StatModifier(float value, StatModifierType type, int order, cocos2d::Sprite* source):Value(value),Type(type),Order(order),Source(source)
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

cocos2d::Sprite* StatModifier::getSource()
{
	return this->Source;
}

const std::vector<StatModifier> EntityStats::getReadOnlyStatModifier()
{
	return statModifier;
}

EntityStats::EntityStats()
{
	baseValue = 0;
	_value = 0;
}

EntityStats::~EntityStats()
{
}

void EntityStats::addModifier(StatModifier& statmodify)
{
	isDirty = true;
	statModifier.push_back(statmodify);
	log("size [%d]", statModifier.size());
}

bool EntityStats::removeModifier(StatModifier& statmodify)
{
	for (int i = 0; i < statModifier.size(); i++)
	{
		if (statmodify.getValue() == statModifier.at(i).getValue()
			|| statmodify.getType() == statModifier.at(i).getType()
			|| statmodify.getOrder() == statModifier.at(i).getOrder()
			)
		{
			isDirty = true;
			statModifier.erase(std::next(statModifier.begin(), i+1));
			log("size [%d]", statModifier.size());
			return true;
		}
	}
	return false;
}

bool EntityStats::removeAllModifier(Sprite* source)
{
	bool remove = false;
	for (int i = statModifier.size()-1; i>= 0; i--)
	{
		if (source == statModifier.at(i).getSource())
		{
			isDirty = true;
			statModifier.erase(std::next(statModifier.begin(), i));
			remove = true;
		}
	}
	return remove;
}

float EntityStats::getValue()
{
	if (isDirty || baseValue != lastBaseValue)
	{
		lastBaseValue = baseValue;
		_value = calculateStatValue();
		isDirty = false;
	}
	return _value;
}
//
float EntityStats::calculateStatValue()
{
	float lastValue = baseValue;
	float sumPercentAdd = 0;
	for (int i = 0; i < statModifier.size(); i++)
	{
		StatModifier modifier = statModifier.at(i);
		switch (modifier.getType())
		{
		case StatModifierType::Flat:
			lastValue += modifier.getValue();
			break;
		case StatModifierType::PercentAdd:
			sumPercentAdd += (modifier.getValue()/100.0f);
			if (i+1 >= statModifier.size() 
				|| statModifier.at(i+1).getType() != StatModifierType::PercentAdd)
			{
				lastValue *= 1 + sumPercentAdd;
				sumPercentAdd = 0;
			}
			break;
		case StatModifierType::PercentMult:
			lastValue *= 1.0f + modifier.getValue()/100.0f;
			break;
		}
	}
	return roundf(lastValue*100)/100;
}

int EntityStats::compareModifierOrder(StatModifier& modA, StatModifier& modB)
{
	if (modA.getOrder() < modB.getOrder())
	{
		return -1;
	}
	else if (modA.getOrder() > modB.getOrder())
	{
		return 1;
	}
	return 0;
}
