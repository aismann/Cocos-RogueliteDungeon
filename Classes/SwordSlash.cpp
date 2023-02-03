#include "SwordSlash.h"
USING_NS_CC;
SwordSlash::SwordSlash():WeaponSkill()
{
	this->setSpriteFrame(SWORD_SLASH, 0);
}

SwordSlash::~SwordSlash()
{
}

void SwordSlash::setLifeTime(float life)
{
	this->lifeTime = life;

	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	this->setAnimation(REPEAT::FOREVER, SWORD_SLASH, frameBegin, frameEnd, frameDelay);
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

float SwordSlash::getDamage()
{
	return WeaponSkill::getDamage();
}
