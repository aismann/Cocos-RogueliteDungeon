#include "Knight.h"
#include "Sword.h"
void Knight::initHero()
{
	this->weaponNode = Sprite::create("baseSprite.png");
	this->weaponNode->setOpacity(0);
	this->weaponNode->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 4);
	this->weaponNode->setLocalZOrder(-1);
	this->addChild(this->weaponNode);

	this->weapon = new Sword();
	this->weapon->setPosition(this->weaponNode->getContentSize().width / 2.f, this->weaponNode->getContentSize().height /2.f);
	this->weaponNode->addChild(this->weapon);

	StatModifier* baseHP = new StatModifier(10, StatModifierType::Flat,this);
	StatModifier* baseSH = new StatModifier(5, StatModifierType::Flat, 0, this);
	StatModifier* baseATK = new StatModifier(4, StatModifierType::Flat, 0, this);
	StatModifier* baseATSP = new StatModifier(0.65, StatModifierType::Flat, 0, this);
	StatModifier* baseMSP = new StatModifier(90, StatModifierType::Flat, 0, this);

	this->maxHealth.addModifier(baseHP);
	this->health = this->maxHealth.getValue();

	this->maxShield.addModifier(baseSH);
	this->shield = this->maxShield.getValue();

	this->maxDamage.addModifier(baseATK);
	this->damage = this->maxDamage.getValue();

	this->maxAttackSpeed.addModifier(baseATSP);
	this->attackSpeed = this->maxAttackSpeed.getValue();

	this->maxMovementSpeed.addModifier(baseMSP);
	this->movementSpeed = this->maxMovementSpeed.getValue();
}

Knight::Knight():Hero()
{
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	this->heroJob = HeroJob::Knight;
	this->setSpriteFrame(KNIGHT_M_IDLE, frameBegin);
	this->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
	this->initHero();
}

Knight::~Knight()
{
}
