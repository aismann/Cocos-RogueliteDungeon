#include "Weapon.h"
USING_NS_CC;
void Weapon::initWeapon()
{
}

Weapon::Weapon():Entity()
{
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
