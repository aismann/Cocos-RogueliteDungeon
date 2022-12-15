#include "Lizard.h"

void Lizard::initHero()
{
	StatModifier* baseMSP = new StatModifier(90, StatModifierType::Flat, 0, this);
	this->movementSpeed.addModifier(baseMSP);
}

Lizard::Lizard(Gender gen):Hero()
{
	this->initHero();
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	if (gen == Gender::Male)
	{
		this->heroJob = HeroJob::Lizard_M;
		this->setSpriteFrame(LIZARD_M_IDLE, frameBegin);
		this->setAnimation(REPEAT::FOREVER, LIZARD_M_IDLE, frameBegin, frameEnd, frameDelay);
	}
	else
	{
		this->heroJob = HeroJob::Lizard_F;
		this->setSpriteFrame(LIZARD_F_IDLE, frameBegin);
		this->setAnimation(REPEAT::FOREVER, LIZARD_F_IDLE, frameBegin, frameEnd, frameDelay);
	}
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
