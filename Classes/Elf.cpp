#include "Elf.h"

void Elf::initHero()
{
	StatModifier* baseMSP = new StatModifier(100, StatModifierType::Flat, 0, this);
	this->maxMovementSpeed.addModifier(baseMSP);
	this->movementSpeed = this->maxMovementSpeed.getValue();
}

Elf::Elf():Hero()
{
	this->initHero();
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	this->heroJob = HeroJob::Elf;
	this->setSpriteFrame(ELF_M_IDLE, frameBegin);
	this->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
}

Elf::~Elf()
{
}

float Elf::getHealth()
{
	return Hero::getHealth();
}

float Elf::getShield()
{
	return Hero::getShield();
}

float Elf::getDamage()
{
	return Hero::getDamage();
}

float Elf::getMovementSpeed()
{
	return Hero::getMovementSpeed();
}
