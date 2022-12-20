#include "Lizard.h"

void Lizard::initHero()
{
	StatModifier* baseMSP = new StatModifier(90, StatModifierType::Flat, 0, this);
	this->movementSpeed.addModifier(baseMSP);
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

float Lizard::getMana()
{
	return Hero::getMana();
}

float Lizard::getDamage()
{
	return Hero::getDamage();
}

float Lizard::getMovementSpeed()
{
	return Hero::getMovementSpeed();
}
