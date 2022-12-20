#include "HeroState.h"
USING_NS_CC;

/*----------------------------------------------------------------------------------------*/
float HeroBaseState::x_axist = 0;
float HeroBaseState::y_axist = 0;
std::vector<EventKeyboard::KeyCode> HeroBaseState::keyList;
std::vector<EventKeyboard::KeyCode>::iterator HeroBaseState::it;
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
	case HeroJob::Lizard_M:
		_entity->setAnimation(REPEAT::FOREVER, LIZARD_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Lizard_F:
		_entity->setAnimation(REPEAT::FOREVER, LIZARD_F_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Wizard_M:
		_entity->setAnimation(REPEAT::FOREVER, WIZARD_M_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Wizard_F:
		_entity->setAnimation(REPEAT::FOREVER, WIZARD_F_IDLE, frameBegin, frameEnd, frameDelay);
		break;
	}
}

void HeroIdleState::onStart(Hero* _entity)
{
	if (keyList.size()!=0)
	{
		for (auto& key : keyList)
		{
			if (key == EventKeyboard::KeyCode::KEY_W
				|| key == EventKeyboard::KeyCode::KEY_S
				|| key == EventKeyboard::KeyCode::KEY_A
				|| key == EventKeyboard::KeyCode::KEY_D)
			{
				//HeroRunState::setRunAnimation(_entity);
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

	if (keyList.size() == 0)
	{
		this->setIdleAnimation(_entity);
	}
}

HeroBaseState* HeroIdleState::onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	
#pragma region Movement
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		keyList.push_back(keycode);
		y_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		keyList.push_back(keycode);
		y_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		keyList.push_back(keycode);
		_entity->setFlippedX(true);
		x_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		keyList.push_back(keycode);
		_entity->setFlippedX(false);
		x_axist++;
		break;
	default:
		break;
	}
	it = std::find(keyList.begin(), keyList.end(), keycode);
	if (it != keyList.end())
	{
		if (*it == EventKeyboard::KeyCode::KEY_W
			|| *it == EventKeyboard::KeyCode::KEY_S
			|| *it == EventKeyboard::KeyCode::KEY_A
			|| *it == EventKeyboard::KeyCode::KEY_D )
		{
			_entity->setEntitySpeed(_entity->getMovementSpeed());
			_entity->setEntityDirection(Vec2(x_axist, y_axist));
			return new HeroRunState();
		}

	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroIdleState::onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		y_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		y_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		x_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		x_axist--;
		break;
	default:
		break;
	}
	it = std::find(keyList.begin(), keyList.end(), keycode);
	if (it != keyList.end())
	{
		if (*it == EventKeyboard::KeyCode::KEY_W
			|| *it == EventKeyboard::KeyCode::KEY_S
			|| *it == EventKeyboard::KeyCode::KEY_A
			|| *it == EventKeyboard::KeyCode::KEY_D)
		{
			keyList.erase(it);
			_entity->setEntitySpeed(_entity->getMovementSpeed());
			_entity->setEntityDirection(Vec2(x_axist, y_axist));
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
	case HeroJob::Lizard_M:
		_entity->setAnimation(REPEAT::FOREVER, LIZARD_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Lizard_F:
		_entity->setAnimation(REPEAT::FOREVER, LIZARD_F_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Wizard_M:
		_entity->setAnimation(REPEAT::FOREVER, WIZARD_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Wizard_F:
		_entity->setAnimation(REPEAT::FOREVER, WIZARD_F_RUN, frameBegin, frameEnd, frameDelay);
		break;
	}
}
void HeroRunState::onStart(Hero* _entity)
{

	this->setRunAnimation(_entity);
}

void HeroRunState::onExit(Hero* _entity)
{

	
}

HeroBaseState* HeroRunState::onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		keyList.push_back(keycode);
		y_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		keyList.push_back(keycode);
		y_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		keyList.push_back(keycode);
		_entity->setFlippedX(true);
		x_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		keyList.push_back(keycode);
		_entity->setFlippedX(false);
		x_axist++;
		break;
	default:
		break;
	}
	it = std::find(keyList.begin(), keyList.end(), keycode);
	if (it != keyList.end())
	{
		if (*it == EventKeyboard::KeyCode::KEY_W
			|| *it == EventKeyboard::KeyCode::KEY_S
			|| *it == EventKeyboard::KeyCode::KEY_A
			|| *it == EventKeyboard::KeyCode::KEY_D)
		{
			_entity->setEntitySpeed(_entity->getMovementSpeed());
			_entity->setEntityDirection(Vec2(x_axist, y_axist));
			return new HeroIdleState();
		}
	}
#pragma endregion
	
	return nullptr;
}

HeroBaseState* HeroRunState::onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		y_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		y_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		x_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		x_axist--;
		break;
	default:
		break;
	}
	it = std::find(keyList.begin(), keyList.end(), keycode);
	if (it != keyList.end())
	{
		if (*it == EventKeyboard::KeyCode::KEY_W
			|| *it == EventKeyboard::KeyCode::KEY_S
			|| *it == EventKeyboard::KeyCode::KEY_A
			|| *it == EventKeyboard::KeyCode::KEY_D)
		{
			keyList.erase(it);
			_entity->setEntitySpeed(_entity->getMovementSpeed());
			_entity->setEntityDirection(Vec2(x_axist, y_axist));
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