#include "HeroState.h"
USING_NS_CC;

//#pragma region SetAnimation
//void HeroState::setIdleAnimation(Hero* hero)
//{
//	int frameBegin = 0;
//	int frameEnd = 3;
//	float frameDelay = 0.15f;
//	switch (_entity->getHeroJob())
//	{
//	case HeroJob::Elf_M:
//		_entity->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroJob::Elf_F:
//		_entity->setAnimation(REPEAT::FOREVER, ELF_F_IDLE, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroJob::Knight_M:
//		_entity->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroJob::Knight_F:
//		_entity->setAnimation(REPEAT::FOREVER, KNIGHT_F_IDLE, frameBegin, frameEnd, frameDelay);
//		break;
//	}
//}
//
//void HeroState::setRunAnimation(Hero* hero)
//{
//	int frameBegin = 0;
//	int frameEnd = 3;
//	float frameDelay = 0.15f;
//	switch (_entity->getHeroJob())
//	{
//	case HeroJob::Elf_M:
//		_entity->setAnimation(REPEAT::FOREVER, ELF_M_RUN, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroJob::Elf_F:
//		_entity->setAnimation(REPEAT::FOREVER, ELF_F_RUN, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroJob::Knight_M:
//		_entity->setAnimation(REPEAT::FOREVER, KNIGHT_M_RUN, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroJob::Knight_F:
//		_entity->setAnimation(REPEAT::FOREVER, KNIGHT_F_RUN, frameBegin, frameEnd, frameDelay);
//		break;
//	}
//}
//#pragma endregion
//
//#pragma region KeyPressChecked
//void HeroState::checkIdleKeyPressed(Hero* hero)
//{
//	bool isMoveKey = false;
//	for (auto& key : keyList)
//	{
//		if (key == this->input->getKeyUp()
//			|| key == this->input->getKeyDown()
//			|| key == this->input->getKeyLeft()
//			|| key == this->input->getKeyRight())
//		{
//			isMoveKey = true;
//			log("[%d]", (int)key);
//		}
//	}
//	if (isMoveKey)
//	{
//		setRunAnimation(hero);
//	}
//
//}void HeroState::checkRunKeyPressed(Hero* hero)
//{
//	bool isMoveKey = false;
//	for (auto& key : keyList)
//	{
//		if (key == this->input->getKeyUp()
//			|| key == this->input->getKeyDown()
//			|| key == this->input->getKeyLeft()
//			|| key == this->input->getKeyRight())
//		{
//			isMoveKey = true;
//			log("[%d]", (int)key);
//		}
//	}
//	if (!isMoveKey)
//
//	{
//		//setIdleAnimation(hero);
//	}
//}
//#pragma endregion
//
//#pragma region KeyReleaseCheched
//void HeroState::checkIdleKeyReleased(Hero* hero)
//{
//	bool isMoveKey = false;
//	for (auto& key : keyList)
//	{
//		if (key == this->input->getKeyUp()
//			|| key == this->input->getKeyDown()
//			|| key == this->input->getKeyLeft()
//			|| key == this->input->getKeyRight())
//		{
//			isMoveKey = true;
//			log("[%d]", (int)key);
//		}
//	}
//	if (!isMoveKey)
//	{
//		setIdleAnimation(hero);
//	}
//}
//
//void HeroState::checkRunKeyReleased(Hero* hero)
//{
//	bool isMoveKey = false;
//	for (auto& key : keyList)
//	{
//		if (key == this->input->getKeyUp()
//			|| key == this->input->getKeyDown()
//			|| key == this->input->getKeyLeft()
//			|| key == this->input->getKeyRight())
//		{
//			isMoveKey = true;
//			log("[%d]", (int)key);
//		}
//	}
//	if (!isMoveKey)
//	{
//		setIdleAnimation(hero);
//	}
//}
//#pragma endregion
//
//#pragma region StateKeyPressed
//void HeroState::onIdleKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	if (keycode == this->input->getKeyUp())
//	{
//		keyList.push_back(this->input->getKeyUp());
//		switchState(State::Run);
//		y_axist++;
//	}
//	if (keycode == this->input->getKeyDown())
//	{
//		keyList.push_back(this->input->getKeyDown());
//		switchState(State::Run);
//		y_axist--;
//	}
//	if (keycode == this->input->getKeyLeft())
//	{
//		keyList.push_back(this->input->getKeyLeft());
//		switchState(State::Run);
//		x_axist--;
//		_entity->setFlippedX(true);
//	}
//	if (keycode == this->input->getKeyRight())
//	{
//		keyList.push_back(this->input->getKeyRight());
//		switchState(State::Run);
//		x_axist++;
//		_entity->setFlippedX(false);
//	}
//	log("i p[%f][%f]", x_axist, y_axist);
//	_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
//}
//
//void HeroState::onRunKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	if (keycode == this->input->getKeyUp())
//	{
//		keyList.push_back(this->input->getKeyUp());
//		y_axist++;
//	}
//	if (keycode == this->input->getKeyDown())
//	{
//		keyList.push_back(this->input->getKeyDown());
//		y_axist--;
//	}
//	if (keycode == this->input->getKeyLeft())
//	{
//		keyList.push_back(this->input->getKeyLeft());
//		x_axist--;
//		_entity->setFlippedX(true);
//	}
//	if (keycode == this->input->getKeyRight())
//	{
//		keyList.push_back(this->input->getKeyRight());
//		x_axist++;
//		_entity->setFlippedX(false);
//	}
//	log("r p[%f][%f]", x_axist, y_axist);
//	_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
//}
//#pragma endregion
//
//#pragma region StateKeyReleased
//void HeroState::onIdleKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	if (keycode == this->input->getKeyUp())
//	{
//		keyList.pop_front();
//		y_axist--;
//	}
//	if (keycode == this->input->getKeyDown())
//	{
//		keyList.pop_front();
//		y_axist++;
//	}
//	if (keycode == this->input->getKeyLeft())
//	{
//		keyList.pop_front();
//		x_axist++;
//	}
//	if (keycode == this->input->getKeyRight())
//	{
//		keyList.pop_front();
//		x_axist--;
//	}
//	log("i r[%f][%f]", x_axist, y_axist);
//	_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
//}
//
//void HeroState::onRunKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	if (keycode == this->input->getKeyUp())
//	{
//		keyList.pop_front();
//		switchState(State::Idle);
//		y_axist--;
//	}
//	if (keycode == this->input->getKeyDown())
//	{
//		keyList.pop_front();
//		switchState(State::Idle);
//		y_axist++;
//	}
//	if (keycode == this->input->getKeyLeft())
//	{
//		keyList.pop_front();
//		switchState(State::Idle);
//		x_axist++;
//	}
//	if (keycode == this->input->getKeyRight())
//	{
//		keyList.pop_front();
//		switchState(State::Idle);
//		x_axist--;
//	}
//	log("r r[%f][%f]", x_axist, y_axist);
//	_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
//}
//#pragma endregion
//
//#pragma region SwitchState
//void HeroState::switchState(State _state)
//{
//	state = _state;
//}
//#pragma endregion
//
//#pragma region OnKeyPressed
//void HeroState::onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	switch (state)
//	{
//	case State::Idle:
//		log("I P");
//		onIdleKeyPressed(hero, keycode, event);
//		checkIdleKeyPressed(hero);
//		break;
//	case State::Run:
//		log("R P");
//		onRunKeyPressed(hero, keycode, event);
//		checkRunKeyPressed(hero);
//		break;
//	default:
//		break;
//	}
//}
//#pragma endregion
//
//#pragma region OnKeyReleased
//void HeroState::onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	switch (state)
//	{
//	case State::Idle:
//		log("I R");
//		onIdleKeyReleased(hero, keycode, event);
//		checkIdleKeyReleased(hero);
//		break;
//	case State::Run:
//		log("R R");
//		onRunKeyReleased(hero, keycode, event);
//		checkRunKeyReleased(hero);
//		break;
//	default:
//		break;
//	}
//}
//#pragma endregion
//
//
//void HeroState::onMouseDown(Hero* hero, cocos2d::Event* event)
//{
//
//}
//
//void HeroState::onMouseUp(Hero* hero, cocos2d::Event* event)
//{
//
//}
//
//void HeroState::onMouseMove(Hero* hero, cocos2d::Event* event)
//{
//
//}
//
//void HeroState::update(Hero* hero, float dt)
//{
//	//log("idle");
//
//}
/*----------------------------------------------------------------------------------------*/
float HeroBaseState::x_axist = 0;
float HeroBaseState::y_axist = 0;
std::vector<cocos2d::EventKeyboard::KeyCode> HeroBaseState::keyList;
/*----------------------------------------------------------------------------------------*/
#pragma region Idle
HeroBaseState* HeroIdleState::onStart(Hero* _entity)
{
	return nullptr;
}

HeroBaseState* HeroIdleState::onExit(Hero* _entity)
{
	return nullptr;
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
			log("Size[%d]", keyList.size());
			log("i p mov[%f][%f]", x_axist, y_axist);
			_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
			return new HeroRunState();
		}
	}
#pragma endregion
	return nullptr;
}

HeroBaseState* HeroIdleState::onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
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
			log("i r mov[%f][%f]", x_axist, y_axist);
			log("Size[%d]", keyList.size());
			return new HeroIdleState();
		}
	}
	return nullptr;
}

HeroBaseState* HeroIdleState::update(Hero* _entity, float dt)
{
	return nullptr;
}
#pragma endregion
/*----------------------------------------------------------------------------------------*/
#pragma region Run
HeroBaseState* HeroRunState::onStart(Hero* _entity)
{
	return nullptr;
}

HeroBaseState* HeroRunState::onExit(Hero* _entity)
{
	return nullptr;
}

HeroBaseState* HeroRunState::onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{

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
	if (it!=keyList.end())
	{
		if (*it == this->input->getKeyUp()
			|| *it == this->input->getKeyDown()
			|| *it == this->input->getKeyLeft()
			|| *it == this->input->getKeyRight())
		{
			log("Size [%d]", keyList.size());
			log("r p mov[%f][%f]", x_axist, y_axist);
			_entity->setSpeedAndDirection(_entity->getMovementSpeed(), Vec2(x_axist, y_axist));
			return new HeroIdleState();
		}
	}
	return nullptr;
}

HeroBaseState* HeroRunState::onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
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
			log("r r mov[%f][%f]", x_axist, y_axist);
			log("Size[%d]", keyList.size());
			return new HeroIdleState();
		}
	}
	return nullptr;
}

HeroBaseState* HeroRunState::update(Hero* _entity, float dt)
{
	return nullptr;
}
#pragma endregion
/*----------------------------------------------------------------------------------------*/

void HeroState::changeState(Hero* _entity, HeroBaseState* newState)
{
	this->activeState->onExit(_entity);
	delete this->activeState;
	this->activeState = newState;
	this->activeState->onStart(_entity);
}
void HeroState::onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	HeroBaseState* newState = this->activeState->onKeyPressed(_entity,keycode,event);
	if (newState)
	{
		changeState(_entity,newState);
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
	HeroBaseState* newState = this->activeState->update(_entity,dt);
	if (newState)
	{
		changeState(_entity, newState);
	}
}