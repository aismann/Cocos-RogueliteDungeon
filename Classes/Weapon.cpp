#include "Weapon.h"
USING_NS_CC;
void Weapon::initWeapon()
{
}

Weapon::Weapon():Entity()
{
	this->setTag(WEAPON_TAG);
	this->isLightAttack = false;
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

bool Weapon::isLightAttackActive()
{
	return this->isLightAttack;
}

void Weapon::update(float dt)
{
}
