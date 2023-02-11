#include "OrcMagic.h"
USING_NS_CC;
OrcMagic::OrcMagic():WeaponSkill()
{
	this->setTag(ENEMY_ATTACK_TAG);
	this->setName("MagicAttack");
	this->setSpriteFrame(ORC_MAGIC, 0);
}

OrcMagic::~OrcMagic()
{
}

void OrcMagic::setLifeTime(float life)
{
	this->lifeTime = life;

	int frameBegin = 0;
	int frameEnd = 0;
	float frameDelay = 0.f;
	this->setAnimation(REPEAT::FOREVER, ORC_MAGIC, frameBegin, frameEnd, frameDelay);
}

float OrcMagic::getLifeTime()
{
	return this->lifeTime;
}

float OrcMagic::lifeTimeCouting(float dt)
{
	if (this->lifeTime > 0)
	{
		return this->lifeTime -= dt;
	}
	return 0.0f;
}

void OrcMagic::setDamage(float value)
{
	WeaponSkill::setDamage(value);
}

float OrcMagic::getDamage()
{
	return WeaponSkill::getDamage();
}
