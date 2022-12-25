#include "EntityStats.h"
USING_NS_CC;

const std::vector<StatModifier*> EntityStats::getReadOnlyStatModifier()
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

void EntityStats::addModifier(StatModifier* statmodify)
{
	isDirty = true;
	statModifier.push_back(statmodify);
}

bool EntityStats::removeModifier(StatModifier* statmodify)
{
	it = std::find(statModifier.begin(),statModifier.end(),statmodify);
	if (it!= statModifier.end())
	{
		isDirty = true;
		statModifier.erase(it);
		return true;
	}
	return false;
}

bool EntityStats::removeAllModifier(Entity* source)
{
	bool remove = false;
	for (auto stat : statModifier)
	{
		if (stat->getSource() == source)
		{
			it = std::find(statModifier.begin(), statModifier.end(), stat);
			isDirty = true;
			statModifier.erase(it);
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
	size_t nextPositon = 0;
	for (auto stat : statModifier)
	{
		StatModifier* mod = stat;
		switch (mod->getType())
		{
		case StatModifierType::Flat:
			lastValue += mod->getValue();
			break;
		case StatModifierType::PercentAdd:
			sumPercentAdd += (mod->getValue() / 100.0f);
			it = std::find(statModifier.begin(), statModifier.end(),mod);
			nextPositon = (it - statModifier.begin()) + 1;
			if (nextPositon >= statModifier.size()
				|| statModifier.at(nextPositon)->getType() != StatModifierType::PercentAdd)
			{
				lastValue *= 1 + sumPercentAdd;
				sumPercentAdd = 0;
			}
			break;
		case StatModifierType::PercentMult:
			lastValue *= 1.0f + mod->getValue() / 100.0f;
			break;
		}
	}
	return round(lastValue*100)/100;
}

int EntityStats::compareModifierOrder(StatModifier* modA, StatModifier* modB)
{
	if (modA->getOrder() < modB->getOrder())
	{
		return -1;
	}
	else if (modA->getOrder() > modB->getOrder())
	{
		return 1;
	}
	return 0;
}
