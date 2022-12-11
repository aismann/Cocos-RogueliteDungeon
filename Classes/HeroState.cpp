#include "HeroState.h"
USING_NS_CC;

#pragma region SetAnimation
void HeroState::setIdleAnimation(Hero* hero)
{
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	switch (hero->getHeroJob())
	{
	case HeroJob::Elf_M:
		hero->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Elf_F:
		hero->setAnimation(REPEAT::FOREVER, ELF_F_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight_M:
		hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight_F:
		hero->setAnimation(REPEAT::FOREVER, KNIGHT_F_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	}
}

void HeroState::setRunAnimation(Hero* hero)
{
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	switch (hero->getHeroJob())
	{
	case HeroJob::Elf_M:
		hero->setAnimation(REPEAT::FOREVER, ELF_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Elf_F:
		hero->setAnimation(REPEAT::FOREVER, ELF_F_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight_M:
		hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight_F:
		hero->setAnimation(REPEAT::FOREVER, KNIGHT_F_RUN, frameBegin, frameEnd, frameDelay);
		break;
	}
}
#pragma endregion

#pragma region KeyPressChecked
void HeroState::checkIdleKeyPressed(Hero* hero)
{
	bool isMoveKey = false;
	for (auto& key : keyList)
	{
		if (key == this->input->getKeyUp()
			|| key == this->input->getKeyDown()
			|| key == this->input->getKeyLeft()
			|| key == this->input->getKeyRight())
		{
			isMoveKey = true;
			log("[%d]", (int)key);
		}
	}
	if (isMoveKey)
	{
		setRunAnimation(hero);
	}

}void HeroState::checkRunKeyPressed(Hero* hero)
{
	bool isMoveKey = false;
	for (auto& key : keyList)
	{
		if (key == this->input->getKeyUp()
			|| key == this->input->getKeyDown()
			|| key == this->input->getKeyLeft()
			|| key == this->input->getKeyRight())
		{
			isMoveKey = true;
			log("[%d]", (int)key);
		}
	}
	if (!isMoveKey)

	{
		//setIdleAnimation(hero);
	}
}
#pragma endregion

#pragma region KeyReleaseCheched
void HeroState::checkIdleKeyReleased(Hero* hero)
{
	bool isMoveKey = false;
	for (auto& key : keyList)
	{
		if (key == this->input->getKeyUp()
			|| key == this->input->getKeyDown()
			|| key == this->input->getKeyLeft()
			|| key == this->input->getKeyRight())
		{
			isMoveKey = true;
			log("[%d]", (int)key);
		}
	}
	if (!isMoveKey)
	{
		setIdleAnimation(hero);
	}
}

void HeroState::checkRunKeyReleased(Hero* hero)
{
	bool isMoveKey = false;
	for (auto& key : keyList)
	{
		if (key == this->input->getKeyUp()
			|| key == this->input->getKeyDown()
			|| key == this->input->getKeyLeft()
			|| key == this->input->getKeyRight())
		{
			isMoveKey = true;
			log("[%d]", (int)key);
		}
	}
	if (!isMoveKey)
	{
		setIdleAnimation(hero);
	}
}
#pragma endregion

#pragma region StateKeyPressed
void HeroState::onIdleKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	if (keycode == this->input->getKeyUp())
	{
		keyList.push_back(this->input->getKeyUp());
		switchState(State::Run);
		directY++;
	}
	if (keycode == this->input->getKeyDown())
	{
		keyList.push_back(this->input->getKeyDown());
		switchState(State::Run);
		directY--;
	}
	if (keycode == this->input->getKeyLeft())
	{
		keyList.push_back(this->input->getKeyLeft());
		switchState(State::Run);
		directX--;
		hero->setFlippedX(true);
	}
	if (keycode == this->input->getKeyRight())
	{
		keyList.push_back(this->input->getKeyRight());
		switchState(State::Run);
		directX++;
		hero->setFlippedX(false);
	}
	log("i p[%f][%f]", directX, directY);
	hero->setSpeedAndDirection(hero->getMovementSpeed(), Vec2(directX, directY));
}

void HeroState::onRunKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	if (keycode == this->input->getKeyUp())
	{
		keyList.push_back(this->input->getKeyUp());
		directY++;
	}
	if (keycode == this->input->getKeyDown())
	{
		keyList.push_back(this->input->getKeyDown());
		directY--;
	}
	if (keycode == this->input->getKeyLeft())
	{
		keyList.push_back(this->input->getKeyLeft());
		directX--;
		hero->setFlippedX(true);
	}
	if (keycode == this->input->getKeyRight())
	{
		keyList.push_back(this->input->getKeyRight());
		directX++;
		hero->setFlippedX(false);
	}
	log("r p[%f][%f]", directX, directY);
	hero->setSpeedAndDirection(hero->getMovementSpeed(), Vec2(directX, directY));
}
#pragma endregion

#pragma region StateKeyReleased
void HeroState::onIdleKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	if (keycode == this->input->getKeyUp())
	{
		keyList.pop_front();
		directY--;
	}
	if (keycode == this->input->getKeyDown())
	{
		keyList.pop_front();
		directY++;
	}
	if (keycode == this->input->getKeyLeft())
	{
		keyList.pop_front();
		directX++;
	}
	if (keycode == this->input->getKeyRight())
	{
		keyList.pop_front();
		directX--;
	}
	log("i r[%f][%f]", directX, directY);
	hero->setSpeedAndDirection(hero->getMovementSpeed(), Vec2(directX, directY));
}

void HeroState::onRunKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	if (keycode == this->input->getKeyUp())
	{
		keyList.pop_front();
		switchState(State::Idle);
		directY--;
	}
	if (keycode == this->input->getKeyDown())
	{
		keyList.pop_front();
		switchState(State::Idle);
		directY++;
	}
	if (keycode == this->input->getKeyLeft())
	{
		keyList.pop_front();
		switchState(State::Idle);
		directX++;
	}
	if (keycode == this->input->getKeyRight())
	{
		keyList.pop_front();
		switchState(State::Idle);
		directX--;
	}
	log("r r[%f][%f]", directX, directY);
	hero->setSpeedAndDirection(hero->getMovementSpeed(), Vec2(directX, directY));
}
#pragma endregion

#pragma region SwitchState
void HeroState::switchState(State _state)
{
	state = _state;
}
#pragma endregion

#pragma region OnKeyPressed
void HeroState::onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	switch (state)
	{
	case State::Idle:
		log("I P");
		onIdleKeyPressed(hero, keycode, event);
		checkIdleKeyPressed(hero);
		break;
	case State::Run:
		log("R P");
		onRunKeyPressed(hero, keycode, event);
		checkRunKeyPressed(hero);
		break;
	default:
		break;
	}
}
#pragma endregion

#pragma region OnKeyReleased
void HeroState::onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	switch (state)
	{
	case State::Idle:
		log("I R");
		onIdleKeyReleased(hero, keycode, event);
		checkIdleKeyReleased(hero);
		break;
	case State::Run:
		log("R R");
		onRunKeyReleased(hero, keycode, event);
		checkRunKeyReleased(hero);
		break;
	default:
		break;
	}
}
#pragma endregion


void HeroState::onMouseDown(Hero* hero, cocos2d::Event* event)
{

}

void HeroState::onMouseUp(Hero* hero, cocos2d::Event* event)
{

}

void HeroState::onMouseMove(Hero* hero, cocos2d::Event* event)
{

}

void HeroState::update(Hero* hero, float dt)
{
	//log("idle");

}
