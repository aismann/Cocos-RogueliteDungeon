#include "HeroState.h"
USING_NS_CC;

/*----------------------------------------------------------------------------------------*/
float HeroBaseState::x_axist = 0;
float HeroBaseState::y_axist = 0;
std::vector<cocos2d::EventKeyboard::KeyCode> HeroBaseState::keyList;
/*----------------------------------------------------------------------------------------*/
#pragma region Idle

void HeroIdleState::setIdleAnimation(Hero* _entity)
{
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	switch (_entity->getHeroJob())
	{
	case HeroJob::Elf_M:
		_entity->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Elf_F:
		_entity->setAnimation(REPEAT::FOREVER, ELF_F_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight_M:
		_entity->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight_F:
		_entity->setAnimation(REPEAT::FOREVER, KNIGHT_F_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	}
}

void HeroIdleState::onStart(Hero* _entity)
{
	log("Idle Start");
	if (keyList.size()!=0)
	{
		for (auto& key : keyList)
		{
			if (key == this->input->getKeyUp()
				|| key == this->input->getKeyDown()
				|| key == this->input->getKeyLeft()
				|| key == this->input->getKeyRight())
			{
				HeroRunState::setRunAnimation(_entity);
			}
		}
	}
	else
	{
		this->setIdleAnimation(_entity);
	}
}

void HeroIdleState::onExit(Hero* _entity)
{
	log("Idle Exit");
	if (keyList.size() == 0)
	{
		this->setIdleAnimation(_entity);
	}
}

HeroBaseState* HeroIdleState::onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	if (keycode == this->input->getKeyUp())
	{
		keyList.push_back(keycode);
		it = std::find(keyList.begin(), keyList.end(), keycode);
		y_axist++;
	}
	if (keycode == this->input->getKeyDown())
	{
		keyList.push_back(keycode);
		it = std::find(keyList.begin(), keyList.end(), keycode);
		y_axist--;
	}
	if (keycode == this->input->getKeyLeft())
	{
		keyList.push_back(keycode);
		it = std::find(keyList.begin(), keyList.end(), keycode);
		x_axist--;
		_entity->setFlippedX(true);
	}
	if (keycode == this->input->getKeyRight())
	{
		keyList.push_back(keycode);
		it = std::find(keyList.begin(), keyList.end(), keycode);
		x_axist++;
		_entity->setFlippedX(false);
	}
	if (it != keyList.end())
	{
		if (*it == this->input->getKeyUp()
			|| *it == this->input->getKeyDown()
			|| *it == this->input->getKeyLeft()
			|| *it == this->input->getKeyRight())
		{
			_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
			return new HeroRunState();
		}
	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroIdleState::onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	if (keycode == this->input->getKeyUp())
	{
		it = std::find(keyList.begin(), keyList.end(), keycode);
		y_axist--;
	}
	if (keycode == this->input->getKeyDown())
	{
		it = std::find(keyList.begin(), keyList.end(), keycode);
		y_axist++;
	}
	if (keycode == this->input->getKeyLeft())
	{
		it = std::find(keyList.begin(), keyList.end(), keycode);
		x_axist++;
	}
	if (keycode == this->input->getKeyRight())
	{
		it = std::find(keyList.begin(), keyList.end(), keycode);
		x_axist--;
	}
	if (it != keyList.end())
	{
		if (*it == this->input->getKeyUp()
			|| *it == this->input->getKeyDown()
			|| *it == this->input->getKeyLeft()
			|| *it == this->input->getKeyRight())
		{
			keyList.erase(it);
			_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
			return new HeroIdleState();
		}
	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroIdleState::update(Hero* _entity, float dt)
{
	return nullptr;
}
#pragma endregion
/*----------------------------------------------------------------------------------------*/
#pragma region Run
void HeroRunState::setRunAnimation(Hero* _entity)
{
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	switch (_entity->getHeroJob())
	{
	case HeroJob::Elf_M:
		_entity->setAnimation(REPEAT::FOREVER, ELF_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Elf_F:
		_entity->setAnimation(REPEAT::FOREVER, ELF_F_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight_M:
		_entity->setAnimation(REPEAT::FOREVER, KNIGHT_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight_F:
		_entity->setAnimation(REPEAT::FOREVER, KNIGHT_F_RUN, frameBegin, frameEnd, frameDelay);
		break;
	}
}
void HeroRunState::onStart(Hero* _entity)
{
	log("Run Start");
	this->setRunAnimation(_entity);
}

void HeroRunState::onExit(Hero* _entity)
{
	log("Run Exit");
	
}

HeroBaseState* HeroRunState::onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	if (keycode == this->input->getKeyUp())
	{
		keyList.push_back(keycode);
		it = std::find(keyList.begin(), keyList.end(), keycode);
		y_axist++;
	}
	if (keycode == this->input->getKeyDown())
	{
		keyList.push_back(keycode);
		it = std::find(keyList.begin(), keyList.end(), keycode);
		y_axist--;
	}
	if (keycode == this->input->getKeyLeft())
	{
		keyList.push_back(keycode);
		it = std::find(keyList.begin(), keyList.end(), keycode);
		x_axist--;
		_entity->setFlippedX(true);
	}
	if (keycode == this->input->getKeyRight())
	{
		keyList.push_back(keycode);
		it = std::find(keyList.begin(), keyList.end(), keycode);
		x_axist++;
		_entity->setFlippedX(false);
	}
	if (it != keyList.end())
	{
		if (*it == this->input->getKeyUp()
			|| *it == this->input->getKeyDown()
			|| *it == this->input->getKeyLeft()
			|| *it == this->input->getKeyRight())
		{
			_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
			return new HeroIdleState();
		}
	}
#pragma endregion
	
	return nullptr;
}

HeroBaseState* HeroRunState::onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	if (keycode == this->input->getKeyUp())
	{
		it = std::find(keyList.begin(), keyList.end(), keycode);
		y_axist--;
	}
	if (keycode == this->input->getKeyDown())
	{
		it = std::find(keyList.begin(), keyList.end(), keycode);
		y_axist++;
	}
	if (keycode == this->input->getKeyLeft())
	{
		it = std::find(keyList.begin(), keyList.end(), keycode);
		x_axist++;
	}
	if (keycode == this->input->getKeyRight())
	{
		it = std::find(keyList.begin(), keyList.end(), keycode);
		x_axist--;
	}
	if (it != keyList.end())
	{
		if (*it == this->input->getKeyUp()
			|| *it == this->input->getKeyDown()
			|| *it == this->input->getKeyLeft()
			|| *it == this->input->getKeyRight())
		{
			keyList.erase(it);
			_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));

			return new HeroIdleState();
		}
	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroRunState::update(Hero* _entity, float dt)
{
	return nullptr;
}

#pragma endregion
/*----------------------------------------------------------------------------------------*/
#pragma region HeroState
void HeroState::changeState(Hero* _entity, HeroBaseState* newState)
{
	this->activeState->onExit(_entity);
	delete this->activeState;
	this->activeState = newState;
	this->activeState->onStart(_entity);
}
void HeroState::onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	HeroBaseState* newState = this->activeState->onKeyPressed(_entity, keycode, event);
	if (newState)
	{
		changeState(_entity, newState);
	}
}
void HeroState::onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	HeroBaseState* newState = this->activeState->onKeyReleased(_entity, keycode, event);
	if (newState)
	{
		changeState(_entity, newState);
	}
}
void HeroState::update(Hero* _entity, float dt)
{
	HeroBaseState* newState = this->activeState->update(_entity, dt);
	if (newState)
	{
		changeState(_entity, newState);
	}
}
#pragma endregion