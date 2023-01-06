#include "Weapon.h"
USING_NS_CC;
void Weapon::initWeapon()
{
}

Weapon::Weapon():Entity()
{
	this->primarySkill = false;
	this->primaryFinished = false;
	this->timeElapsed = 0;
}

Weapon::~Weapon()
{
}

bool Weapon::isPrimarySkillActive()
{
	return this->primarySkill;
}

void Weapon::update(float dt)
{
}
