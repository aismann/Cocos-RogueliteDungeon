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
	this->hero = NULL;
}

HeroManager::~HeroManager()
{
}

void HeroManager::spawnHero(HeroJob heroJob, cocos2d::Vec2& position)
{
	switch (heroJob)
	{
	case HeroJob::Elf_M:
		this->hero = new Elf(Gender::Male);
		break;
	case HeroJob::Elf_F:
		this->hero = new Elf(Gender::Female);
		break;
	case HeroJob::Knight_M:
		this->hero = new Knight(Gender::Male);
		break;
	case HeroJob::Knight_F:
		this->hero = new Knight(Gender::Female);
		break;
	case HeroJob::Lizard_M:
		this->hero = new Lizard(Gender::Male);
		break;
	case HeroJob::Lizard_F:
		this->hero = new Lizard(Gender::Female);
		break;
	case HeroJob::Wizard_M:
		this->hero = new Wizard(Gender::Male);
		break;
	case HeroJob::Wizard_F:
		this->hero = new Wizard(Gender::Female);
		break;
	}
	this->hero->setPosition(position);
	this->initListener();
}

Hero* HeroManager::getHero()
{
	return this->hero;
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
	//this->state->update(this->hero,dt);
}
