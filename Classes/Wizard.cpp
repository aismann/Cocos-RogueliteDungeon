#include "Wizard.h"

void Wizard::initHero()
{
	StatModifier* baseMSP = new StatModifier(90, StatModifierType::Flat, 0, this);
	this->maxMovementSpeed.addModifier(baseMSP);
	this->movementSpeed = this->maxMovementSpeed.getValue();
}

Wizard::Wizard():Hero()
{
	this->initHero();
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	this->heroJob = HeroJob::Wizard;
	this->setSpriteFrame(WIZARD_F_IDLE, frameBegin);
	this->setAnimation(REPEAT::FOREVER, WIZARD_F_IDLE, frameBegin, frameEnd, frameDelay);
}

Wizard::~Wizard()
{
}

float Wizard::getHealth()
{
	return Hero::getHealth();
}

float Wizard::getShield()
{
	return Hero::getShield();
}

float Wizard::getDamage()
{
	return Hero::getDamage();
}

float Wizard::getMovementSpeed()
{
	return Hero::getMovementSpeed();
}
