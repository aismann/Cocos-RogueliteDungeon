#include "Sword.h"
USING_NS_CC;
void Sword::initWeapon()
{
	//StatModifier* baseAtk = new StatModifier(5, StatModifierType::Flat, 0, this);
	//this->damage.addModifier(baseAtk);
	//StatModifier* baseAtSp = new StatModifier(5, StatModifierType::Flat, 0, this);
	//this->attackSpeed.addModifier(baseAtSp);
}

Sword::Sword():Weapon()
{
	this->initWeapon();
	this->setSpriteFrame(SWORD,0,false);
}

Sword::~Sword()
{
}

float Sword::getDamage()
{
	return Weapon::getDamage();
}

float Sword::getAttackSpeed()
{
	return Weapon::getAttackSpeed();
}

void Sword::primaryAttack()
{
	if (!primaryAttacking)
	{
		if (!isFlippedX())
		{	
			this->primaryAttacking = true;
			this->weaponDegree = -105;
			this->setRotation(this->weaponDegree);
		}
		else
		{
			this->primaryAttacking = true;
			this->weaponDegree = 105;
			this->setRotation(this->weaponDegree);
		}
	}
}

void Sword::update(float dt)
{
	if (this->primaryAttacking)
	{
		if (!isFlippedX())
		{
			this->weaponDegree += 5;
			this->setRotation(this->weaponDegree);
			if (this->weaponDegree >= 105)
			{
				this->setRotation(0);
				this->primaryAttacking = false;
				this->primaryAttackFinished = true;
			}
		}
		else
		{
			this->weaponDegree -= 5;
			this->setRotation(this->weaponDegree);
			if (this->weaponDegree >= -105)
			{
				this->setRotation(0);
				this->primaryAttacking = false;
				this->primaryAttackFinished = true;
			}
		}
	}
}
