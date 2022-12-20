#include "Hero.h"

USING_NS_CC;

void Hero::initHero()
{
    StatModifier* baseHP = new StatModifier(10, StatModifierType::Flat);
    this->health.addModifier(baseHP);
    StatModifier* baseMP = new StatModifier(5, StatModifierType::Flat, 0, this);
    this->mana.addModifier(baseMP);
    StatModifier* baseATK = new StatModifier(5, StatModifierType::Flat, 0, this);
    this->damage.addModifier(baseATK);
}

Hero::Hero():Entity()
{
    heroJob = HeroJob::None;
}

Hero::~Hero()
{
}
HeroJob Hero::getHeroJob()
{
    return this->heroJob;
}
float Hero::getHealth()
{
    return this->health.getValue();
}

float Hero::getMana()
{
    return this->mana.getValue();
}

float Hero::getDamage()
{
    return this->damage.getValue();
}

float Hero::getMovementSpeed()
{
    return this->movementSpeed.getValue();
}