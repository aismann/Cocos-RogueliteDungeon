#include "BossZombiePunch.h"
USING_NS_CC;
BossZombiePunch::BossZombiePunch():WeaponSkill()
{
	this->setTag(ENEMY_ATTACK_TAG);
	this->setName("BossAttack");
	this->setSpriteFrame(ZOMBIEBOSS_PUNCH, 0);
}

BossZombiePunch::~BossZombiePunch()
{
}

void BossZombiePunch::setLifeTime(float life)
{
	this->lifeTime = life;

	int frameBegin = 0;
	int frameEnd = 0;
	float frameDelay = 0.f;
	this->setAnimation(REPEAT::FOREVER, ZOMBIEBOSS_PUNCH, frameBegin, frameEnd, frameDelay);
}

float BossZombiePunch::getLifeTime()
{
	return this->lifeTime;
}

float BossZombiePunch::lifeTimeCouting(float dt)
{
	if (this->lifeTime > 0)
	{
		return this->lifeTime -= dt;
	}
	return 0.0f;
}

void BossZombiePunch::setDamage(float value)
{
	WeaponSkill::setDamage(value);
}

float BossZombiePunch::getDamage()
{
	return WeaponSkill::getDamage();
}
