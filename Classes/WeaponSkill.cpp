#include "WeaponSkill.h"
#include "HeroManager.h"
USING_NS_CC;

WeaponSkill::WeaponSkill():Entity()
{
	this->setTag(PLAYER_ATTACK_TAG);
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

float WeaponSkill::getDamage()
{
	return Singleton<HeroManager>::getIntsance()->getHero()->getDamage();
}