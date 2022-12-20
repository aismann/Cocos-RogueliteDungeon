#include "Knight.h"

void Knight::initHero()
{
	StatModifier* baseMSP = new StatModifier(90, StatModifierType::Flat, 0, this);
	this->movementSpeed.addModifier(baseMSP);
}

Knight::Knight():Hero()
{
	this->initHero();
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	this->heroJob = HeroJob::Knight;
	this->setSpriteFrame(KNIGHT_M_IDLE, frameBegin);
	this->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
}

Knight::~Knight()
{
}

float Knight::getHealth()
{
	return Hero::getHealth();
}

float Knight::getMana()
{
	return Hero::getMana();
}

float Knight::getDamage()
{
	return Hero::getDamage();
}

float Knight::getMovementSpeed()
{
	return Hero::getMovementSpeed();
}
