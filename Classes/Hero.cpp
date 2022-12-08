#include "Hero.h"

USING_NS_CC;

void Hero::initHero()
{
    StatModifier baseHP(10, StatModifierType::Flat, 0, this);
    this->health_point.addModifier(baseHP);
    StatModifier baseMP(5, StatModifierType::Flat, 0, NULL);
    this->mana_point.addModifier(baseMP);
    StatModifier baseATK(5, StatModifierType::Flat, 0, NULL);
    this->damage_point.addModifier(baseATK);
    StatModifier baseMSP(5, StatModifierType::Flat, 0, NULL);
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
        this->setSpriteFrame(ELF_M_IDLE, frameBegin);
        this->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Elf_F:
        this->setSpriteFrame(ELF_F_IDLE, frameBegin);
        this->setAnimation(REPEAT::FOREVER, ELF_F_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Knight_M:
        this->setSpriteFrame(KNIGHT_M_IDLE, frameBegin);
        this->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Knight_F:
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
