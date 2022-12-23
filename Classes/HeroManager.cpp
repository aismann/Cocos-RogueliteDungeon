#include "HeroManager.h"
USING_NS_CC;
void HeroManager::initListener()
{
	// Init mouse listener
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(HeroManager::onMouseDown, this);
	mouseListener->onMouseUp = CC_CALLBACK_1(HeroManager::onMouseUp, this);
	mouseListener->onMouseMove = CC_CALLBACK_1(HeroManager::onMouseMove, this);
	this->hero->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this->hero);

	// Init keyboard listener
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HeroManager::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HeroManager::onKeyReleased, this);
	this->hero->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this->hero);
}

HeroManager::HeroManager()
{
    this->scene = nullptr;
	this->hero = nullptr;
    this->state = new HeroState();
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

	this->initListener();

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

void HeroManager::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	state->onKeyPressed(this->hero,keycode,event);
}

void HeroManager::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	state->onKeyReleased(this->hero, keycode, event);
}

void HeroManager::onMouseDown(cocos2d::Event* event)
{
	state->onMouseDown(this->hero, event);
}

void HeroManager::onMouseUp(cocos2d::Event* event)
{
	state->onMouseUp(this->hero, event);
}

void HeroManager::onMouseMove(cocos2d::Event* event)
{
	state->onMouseMove(this->hero, event);
}

void HeroManager::update(float dt)
{
	//log("[%f][%f]",lastMousePositon.x,lastMousePositon.y);
	this->hero->update(dt);
	this->state->update(this->hero,dt);
}
