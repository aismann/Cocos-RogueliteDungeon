#include "BossZombieGround.h"
USING_NS_CC;
BossZombieGround::BossZombieGround():WeaponSkill()
{
	this->setLocalZOrder(-1);
	this->setTag(ENEMY_ATTACK_TAG);
	this->setName("BossSkill");
	this->setSpriteFrame(ZOMBIEBOSS_GROUND, 0);
	this->setScale(3);
}

BossZombieGround::~BossZombieGround()
{
}

void BossZombieGround::setLifeTime(float life)
{
	this->lifeTime = life;

	int frameBegin = 0;
	int frameEnd = 2;
	float frameDelay = 0.f;
	this->setAnimation(REPEAT::FOREVER, ZOMBIEBOSS_GROUND, frameBegin, frameEnd, frameDelay);
}

float BossZombieGround::getLifeTime()
{
	return this->lifeTime;
}

float BossZombieGround::lifeTimeCouting(float dt)
{
	if (this->lifeTime > 0)
	{
		return this->lifeTime -= dt;
	}
	return 0.0f;
}

void BossZombieGround::setDamage(float value)
{
	WeaponSkill::setDamage(value);
}

float BossZombieGround::getDamage()
{
	return WeaponSkill::getDamage();
}
