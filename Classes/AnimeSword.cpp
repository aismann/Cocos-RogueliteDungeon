#include "AnimeSword.h"
USING_NS_CC;
void AnimeSword::initWeapon()
{
	//StatModifier* baseAtk = new StatModifier(5, StatModifierType::Flat, 0, this);
	//this->damage.addModifier(baseAtk);
	//StatModifier* baseAtSp = new StatModifier(5, StatModifierType::Flat, 0, this);
	//this->attackSpeed.addModifier(baseAtSp);
}

AnimeSword::AnimeSword():Weapon()
{
	this->initWeapon();
	this->setSpriteFrame(SAW_SWORD,0);
}

AnimeSword::~AnimeSword()
{
}

float AnimeSword::getDamage()
{
	return Weapon::getDamage();
}

float AnimeSword::getAttackSpeed()
{
	return Weapon::getAttackSpeed();
}