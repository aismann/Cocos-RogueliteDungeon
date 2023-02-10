#include "HeroIdleState.h"
#include "HeroRunState.h"
USING_NS_CC;

#pragma region Idle

void HeroIdleState::setIdleAnimation()
{
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	switch (hero->getHeroJob())
	{
	case HeroJob::Elf:
		hero->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight:
		hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Lizard:
		hero->setAnimation(REPEAT::FOREVER, LIZARD_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Wizard:
		hero->setAnimation(REPEAT::FOREVER, WIZARD_F_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	}
}

void HeroIdleState::onStart()
{
	if (keyList.size() == 0)
	{
		this->setIdleAnimation();
	}
}

void HeroIdleState::onExit()
{
	if (keyList.size() == 0)
	{
		this->setIdleAnimation();
	}
}

HeroBaseState* HeroIdleState::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		keyList.push_back(keycode);
		hero->setYCoordinate(1);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		keyList.push_back(keycode);
		hero->setYCoordinate(-1);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		keyList.push_back(keycode);
		hero->setFlippedX(true);
		hero->setXCoordinate(-1);
		break;
	case EventKeyboard::KeyCode::KEY_D:
		keyList.push_back(keycode);
		hero->setFlippedX(false);
		hero->setXCoordinate(1);
		break;
	default:
		break;
	}
	keyIt= std::find(keyList.begin(), keyList.end(), keycode);
	if (keyIt!= keyList.end())
	{
		if (*keyIt== EventKeyboard::KeyCode::KEY_W
			|| *keyIt== EventKeyboard::KeyCode::KEY_S
			|| *keyIt== EventKeyboard::KeyCode::KEY_A
			|| *keyIt== EventKeyboard::KeyCode::KEY_D)
		{
			hero->setSpeed(hero->getMovementSpeed());
			hero->setDirection(Vec2(hero->getXCoordinate(), hero->getYCoordinate()));
			return new HeroRunState();
		}

	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroIdleState::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{

#pragma region Movement
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		hero->setYCoordinate(-1);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		hero->setYCoordinate(1);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		hero->setXCoordinate(1);
		break;
	case EventKeyboard::KeyCode::KEY_D:
		hero->setXCoordinate(-1);
		break;
	default:
		break;
	}
	keyIt= std::find(keyList.begin(), keyList.end(), keycode);
	if (keyIt!= keyList.end())
	{
		if (*keyIt== EventKeyboard::KeyCode::KEY_W
			|| *keyIt== EventKeyboard::KeyCode::KEY_S
			|| *keyIt== EventKeyboard::KeyCode::KEY_A
			|| *keyIt== EventKeyboard::KeyCode::KEY_D)
		{
			keyList.erase(keyIt);
			hero->setSpeed(hero->getMovementSpeed());
			hero->setDirection(Vec2(hero->getXCoordinate(), hero->getYCoordinate()));
			return new HeroIdleState();
		}
	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroIdleState::onMouseDown(cocos2d::Event* event)
{
	hero->getWeapon()->setIsAttack(true);
	return nullptr;
}

HeroBaseState* HeroIdleState::onMouseUp(cocos2d::Event* event)
{
	hero->getWeapon()->setIsAttack(false);
	return nullptr;
}

HeroBaseState* HeroIdleState::onMouseMove(cocos2d::Event* event)
{
	EventMouse* e = (EventMouse*)event;
	this->lastMousePositon = e->getLocationInView();
	hero->rotateWeaponByCursor(this->lastMousePositon);
	return nullptr;
}

HeroBaseState* HeroIdleState::update(float dt)
{
	hero->getWeapon()->update(dt);
	return nullptr;
}
#pragma endregion

