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
	this->setSpriteFrame(ANIME_SWORD,0);
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

void AnimeSword::lightAttack()
{
	if (!isLightAttack)
	{
		this->isLightAttack = true;
		if (this->isFlippedX())
		{
			this->weaponDegree = 105;
		}
		else
		{
			this->weaponDegree = -105;
		}
		this->setRotation(this->weaponDegree);
	}
}

void AnimeSword::update(float dt)
{
	if (this->isLightAttack && this->isFlippedX() == false)
	{
		this->weaponDegree += 15;
		this->setRotation(this->weaponDegree);
		if (this->getRotation() >= 105)
		{
			this->weaponDegree = -105;
			this->setRotation(0);
			this->isLightAttack = false;
		}
	}
	else if(this->isLightAttack && this->isFlippedX() == true)
	{
		this->weaponDegree -= 15;
		this->setRotation(this->weaponDegree);
		if (this->getRotation() <= -105)
		{
			this->weaponDegree = 105;
			this->setRotation(0);
			this->isLightAttack = false;
		}
	}
}
