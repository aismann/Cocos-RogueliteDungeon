#include "HeroManager.h"
USING_NS_CC;
void HeroManager::zeroAxist()
{
	this->xAxist = 0;
	this->yAxist = 0;
}
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
	this->hero = NULL;
	this->zeroAxist();
}

HeroManager::~HeroManager()
{
}

void HeroManager::spawnHero(HeroClasses classes, cocos2d::Vec2& position)
{
	hero = new Hero(classes,position);
	this->initListener();
}

Hero* HeroManager::getHero()
{
	return this->hero;
}

void HeroManager::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{

}

void HeroManager::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{

}

void HeroManager::onMouseDown(cocos2d::Event* event)
{
}

void HeroManager::onMouseUp(cocos2d::Event* event)
{
}

void HeroManager::onMouseMove(cocos2d::Event* event)
{
	EventMouse* e = (EventMouse*)event;
	this->lastMousePositon = e->getLocationInView();
}

void HeroManager::update(float dt)
{
	//log("[%f][%f]",lastMousePositon.x,lastMousePositon.y);
	this->hero->update(dt);
}
