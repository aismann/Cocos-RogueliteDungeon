#include "HeroManager.h"
USING_NS_CC;

HeroManager::HeroManager()
{
    this->scene = nullptr;
	this->hero = nullptr;
    this->weaponNode = nullptr;
}

HeroManager::~HeroManager()
{
}

void HeroManager::setScene(cocos2d::Scene* scene)
{
	this->scene = scene;
}

void HeroManager::setVisibleSize(cocos2d::Vec2 visibleSize)
{
	this->visibleSize = visibleSize;
}

cocos2d::Vec2 HeroManager::getVisibleSize()
{
	return this->visibleSize;
}

void HeroManager::spawnHero(HeroJob heroJob, cocos2d::Vec2& position)
{
	switch (heroJob)
	{
	case HeroJob::Elf:
		this->hero = new Elf();
		break;
	case HeroJob::Knight:
		this->hero = new Knight();
		break;
	case HeroJob::Lizard:
		this->hero = new Lizard();
		break;
	case HeroJob::Wizard:
		this->hero = new Wizard();
		break;
	}

	this->hero->setPosition(position);
	this->scene->addChild(this->hero,1);

	this->weaponNode = Sprite::create("baseSprite.png");
	this->weaponNode->setOpacity(0);
	this->weaponNode->setTag(WEAPON_NODE_TAG);
	this->weaponNode->setPosition(this->hero->getContentSize().width / 2, this->hero->getContentSize().height / 4);
	this->hero->addChild(this->weaponNode);
}

Hero* HeroManager::getHero()
{
	return this->hero;
}

cocos2d::Node* HeroManager::getWeaponNode()
{
    return this->weaponNode;
}

void HeroManager::update(float dt)
{
	//log("[%f][%f]",lastMousePositon.x,lastMousePositon.y);
	this->hero->update(dt);
}
