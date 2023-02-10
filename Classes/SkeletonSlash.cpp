#include "SkeletonSlash.h"
USING_NS_CC;
SkeletonSlash::SkeletonSlash():WeaponSkill()
{
	this->setTag(ENEMY_ATTACK_TAG);
	this->setName("EnemyAttack");
	this->setSpriteFrame(SKELETON_SLASH, 0);
}

SkeletonSlash::~SkeletonSlash()
{
}

void SkeletonSlash::setLifeTime(float life)
{
	this->lifeTime = life;

	int frameBegin = 0;
	int frameEnd = 0;
	float frameDelay = 0.f;
	this->setAnimation(REPEAT::FOREVER, SKELETON_SLASH, frameBegin, frameEnd, frameDelay);
}

float SkeletonSlash::getLifeTime()
{
	return this->lifeTime;
}

float SkeletonSlash::lifeTimeCouting(float dt)
{
	if (this->lifeTime > 0)
	{
		return this->lifeTime -= dt;
	}
	return 0.0f;
}

void SkeletonSlash::setDamage(float value)
{
	WeaponSkill::setDamage(value);
}

float SkeletonSlash::getDamage()
{
	return WeaponSkill::getDamage();
}
