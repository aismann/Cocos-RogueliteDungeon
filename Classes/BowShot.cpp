#include "BowShot.h"
#include "PhysicsShapeCache.h"
USING_NS_CC;
BowShot::BowShot():WeaponSkill()
{
	this->setSpriteFrame(BOW_SHOT, 0);
}

BowShot::~BowShot()
{
}

void BowShot::setLifeTime(float life)
{
	this->lifeTime = life;
}

float BowShot::getLifeTime()
{
	return this->lifeTime;
}

float BowShot::lifeTimeCouting(float dt)
{
	if (this->lifeTime > 0)
	{
		return this->lifeTime -= dt;
	}
	return 0.0f;
}

float BowShot::getDamage()
{
	return WeaponSkill::getDamage();
}
