#include "WeaponSkill.h"
#include "HeroManager.h"
USING_NS_CC;

WeaponSkill::WeaponSkill():Entity()
{
	this->lifeTime = 0;
}

WeaponSkill::~WeaponSkill()
{
}

void WeaponSkill::setLifeTime(float life)
{
}

float WeaponSkill::getLifeTime()
{
	return 0.0f;
}

float WeaponSkill::lifeTimeCouting(float dt)
{
	return 0.0f;
}

void WeaponSkill::setDamage(float value)
{
	this->damage = value;
}

float WeaponSkill::getDamage()
{
	return this->damage;
}

void WeaponSkill::takeHit()
{

}

