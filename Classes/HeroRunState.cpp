#include "HeroRunState.h"
#include "HeroIdleState.h"
USING_NS_CC;

#pragma region Run
void HeroRunState::setRunAnimation()
{
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	switch (hero->getHeroJob())
	{
	case HeroJob::Elf:
		hero->setAnimation(REPEAT::FOREVER, ELF_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight:
		hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Lizard:
		hero->setAnimation(REPEAT::FOREVER, LIZARD_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Wizard:
		hero->setAnimation(REPEAT::FOREVER, WIZARD_F_RUN, frameBegin, frameEnd, frameDelay);
		break;
	}
}
void HeroRunState::onStart()
{

	this->setRunAnimation();
}

void HeroRunState::onExit()
{


}

HeroBaseState* HeroRunState::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
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
			return new HeroIdleState();
		}
	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroRunState::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
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

HeroBaseState* HeroRunState::onMouseDown(cocos2d::Event* event)
{
	hero->getWeapon()->PrimarySkill(hero->getWeaponNode());
	return nullptr;
}

HeroBaseState* HeroRunState::onMouseUp(cocos2d::Event* event)
{
	return nullptr;
}

HeroBaseState* HeroRunState::onMouseMove(cocos2d::Event* event)
{
	EventMouse* e = (EventMouse*)event;
	this->lastMousePositon = e->getLocationInView();
	hero->rotateWeaponByCursor(this->lastMousePositon);
	return nullptr;
}

HeroBaseState* HeroRunState::update(float dt)
{
	hero->getWeapon()->update(dt);

	return nullptr;
}

#pragma endregion