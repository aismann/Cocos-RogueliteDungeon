#include "Hero.h"

USING_NS_CC;

void Hero::initHero()
{
    StatModifier* baseHP = new StatModifier(10, StatModifierType::Flat);
    this->health_point.addModifier(baseHP);
    StatModifier* baseMP = new StatModifier(5, StatModifierType::Flat, 0, this);
    this->mana_point.addModifier(baseMP);
    StatModifier* baseATK = new StatModifier(5, StatModifierType::Flat, 0, this);
    this->damage_point.addModifier(baseATK);
    StatModifier* baseMSP = new StatModifier(100, StatModifierType::Flat, 0, this);
    this->movement_speed.addModifier(baseMSP);
}

Hero::Hero(HeroClasses classes, cocos2d::Vec2& position):Entity()
{
    /*initHero*/
    this->initHero();
    /*choice hero class*/
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    switch (classes)
    {
    case HeroClasses::Elf_M:
        this->heroClass = HeroClasses::Elf_M;
        this->setSpriteFrame(ELF_M_IDLE, frameBegin);
        this->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Elf_F:
        this->heroClass = HeroClasses::Elf_F;
        this->setSpriteFrame(ELF_F_IDLE, frameBegin);
        this->setAnimation(REPEAT::FOREVER, ELF_F_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Knight_M:
        this->heroClass = HeroClasses::Knight_M;
        this->setSpriteFrame(KNIGHT_M_IDLE, frameBegin);
        this->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Knight_F:
        this->heroClass = HeroClasses::Knight_F;
        this->setSpriteFrame(KNIGHT_F_IDLE, frameBegin);
        this->setAnimation(REPEAT::FOREVER, KNIGHT_F_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    }
    /*set hero position*/
    this->setPosition(position);
}

Hero::~Hero()
{
}

float Hero::getHealthPoint()
{
    return this->health_point.getValue();
}

HeroClasses Hero::getHeroClass()
{
    return this->heroClass;
}

float Hero::getManaPoint()
{
    return this->mana_point.getValue();
}

float Hero::getDamagePoint()
{
    return this->damage_point.getValue();
}

float Hero::getMovementSpeed()
{
    return this->movement_speed.getValue();
}