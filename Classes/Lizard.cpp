#include "Lizard.h"
USING_NS_CC;
void Lizard::initHero()
{
	StatModifier* baseMSP = new StatModifier(90, StatModifierType::Flat, 0, this);
	this->maxMovementSpeed.addModifier(baseMSP);
	this->movementSpeed = this->maxMovementSpeed.getValue();
}

Lizard::Lizard():Hero()
{
	this->initHero();
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	this->heroJob = HeroJob::Lizard;
	this->setSpriteFrame(LIZARD_M_IDLE, frameBegin);
	this->setAnimation(REPEAT::FOREVER, LIZARD_M_IDLE, frameBegin, frameEnd, frameDelay);
}

Lizard::~Lizard()
{
}

float Lizard::getHealth()
{
	return Hero::getHealth();
}

float Lizard::getShield()
{
	return Hero::getShield();
}

float Lizard::getDamage()
{
	return Hero::getDamage();
}

float Lizard::getMovementSpeed()
{
	return Hero::getMovementSpeed();
}
