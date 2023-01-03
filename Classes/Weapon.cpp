#include "Weapon.h"
USING_NS_CC;
void Weapon::initWeapon()
{
}

Weapon::Weapon():Entity()
{
	this->setTag(WEAPON_TAG);
	this->primaryAttacking = false;
	this->primaryAttackFinished = false;
	this->weaponDegree = 0;
}

Weapon::~Weapon()
{
}

float Weapon::getDamage()
{
	return this->damage.getValue();
}

float Weapon::getAttackSpeed()
{
	return this->attackSpeed.getValue();
}

void Weapon::lightAttack()
{

}

bool Weapon::isPrimaryAttacking()
{
	return this->primaryAttacking;
}

void Weapon::update(float dt)
{
}
