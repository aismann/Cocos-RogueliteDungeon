#include "SwordSlash.h"
USING_NS_CC;
SwordSlash::SwordSlash():WeaponSkill()
{
	this->setTag(PLAYER_ATTACK_TAG);
	this->setSpriteFrame(SWORD_SLASH, 0);
	int frameBegin = 0;
	int frameEnd = 2;
	float frameDelay = 0.15f;
	this->setAnimation(REPEAT::FOREVER, SWORD_SLASH, frameBegin, frameEnd, frameDelay);
}

SwordSlash::~SwordSlash()
{
}

void SwordSlash::setLifeTime(float life)
{
	this->lifeTime = life;
}

float SwordSlash::getLifeTime()
{
	return this->lifeTime;
}

float SwordSlash::lifeTimeCouting(float dt)
{
	if (this->lifeTime > 0)
	{
		return this->lifeTime -= dt;
	}
	return 0.0f;
}

void SwordSlash::setDamage(float value)
{
	WeaponSkill::setDamage(value);
}

float SwordSlash::getDamage()
{
	return WeaponSkill::getDamage();
}
