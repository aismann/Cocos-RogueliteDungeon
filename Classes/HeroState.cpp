#include "HeroState.h"
USING_NS_CC;

//#pragma region HEROSTATE
//HeroState::HeroState()
//{
//	this->input->setKeyUp(EventKeyboard::KeyCode::KEY_W);
//	this->input->setKeyDown(EventKeyboard::KeyCode::KEY_S);
//	this->input->setKeyLeft(EventKeyboard::KeyCode::KEY_A);
//	this->input->setKeyRight(EventKeyboard::KeyCode::KEY_D);
//}
//void HeroState::update(Hero* hero, float dt)
//{
//	float smoothspeed = hero->getMovementSpeed();
//	smoothspeed *= Director::getInstance()->getAnimationInterval() / dt;
//	hero->getPhysicsBody()->setVelocity(smoothspeed * hero->getDirection());
//}
//#pragma endregion
//
//#pragma region IDLE
//IdleState::IdleState()
//{
//}
//
//IdleState::~IdleState()
//{
//}
//
//void IdleState::onKeyPressed(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	int frameBegin = 0;
//	int frameEnd = 3;
//	float frameDelay = 0.15f;
//	EventKeyboard* e = (EventKeyboard*)event;
//	switch (hero->getHeroClass())
//	{
//	case HeroClasses::Elf_M:
//		hero->setAnimation(REPEAT::FOREVER, ELF_M_RUN, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroClasses::Elf_F:
//		hero->setAnimation(REPEAT::FOREVER, ELF_F_RUN, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroClasses::Knight_M:
//		hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_RUN, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroClasses::Knight_F:
//		hero->setAnimation(REPEAT::FOREVER, KNIGHT_F_RUN, frameBegin, frameEnd, frameDelay);
//		break;
//	}
//	if (keycode == this->input->getKeyUp())
//	{
//		yAxist++;
//	}
//	if (keycode == this->input->getKeyDown())
//	{
//		yAxist--;
//	}
//	if (keycode == this->input->getKeyLeft())
//	{
//		xAxist--;
//		hero->setFlippedX(true);
//	}
//	if (keycode == this->input->getKeyRight())
//	{
//		xAxist++;
//		hero->setFlippedX(false);
//	}
//	hero->setSpeedAndDirection(hero->getMovementSpeed(), Vec2(xAxist, yAxist));
//}
//
//void IdleState::onKeyReleased(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	int frameBegin = 0;
//	int frameEnd = 3;
//	float frameDelay = 0.15f;
//	EventKeyboard* e = (EventKeyboard*)event;
//	switch (hero->getHeroClass())
//	{
//	case HeroClasses::Elf_M:
//		hero->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroClasses::Elf_F:
//		hero->setAnimation(REPEAT::FOREVER, ELF_F_IDLE, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroClasses::Knight_M:
//		hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
//		break;
//	case HeroClasses::Knight_F:
//		hero->setAnimation(REPEAT::FOREVER, KNIGHT_F_IDLE, frameBegin, frameEnd, frameDelay);
//		break;
//	}
//	if (keycode == this->input->getKeyUp())
//	{
//		yAxist--;
//	}
//	if (keycode == this->input->getKeyDown())
//	{
//		yAxist++;
//	}
//	if (keycode == this->input->getKeyLeft())
//	{
//		xAxist++;
//	}
//	if (keycode == this->input->getKeyRight())
//	{
//		xAxist--;
//	}
//	hero->setSpeedAndDirection(hero->getMovementSpeed(),Vec2(xAxist,yAxist));
//}
//
//void IdleState::onMouseDown(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event)
//{
//}
//
//void IdleState::onMouseUp(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event)
//{
//}
//
//void IdleState::onMouseMove(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event)
//{
//}
//
//#pragma endregion
//
//#pragma region RUN
//RunState::RunState()
//{
//
//}
//
//RunState::~RunState()
//{
//}
//
//void RunState::onKeyPressed(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//	EventKeyboard* e = (EventKeyboard*)event;
//	if (keycode == this->input->getKeyUp())
//	{
//		yAxist++;
//	}
//	if (keycode == this->input->getKeyDown())
//	{
//		yAxist--;
//	}
//	if (keycode == this->input->getKeyLeft())
//	{
//		xAxist--;
//		hero->setFlippedX(true);
//	}
//	if (keycode == this->input->getKeyRight())
//	{
//		xAxist++;
//		hero->setFlippedX(false);
//	}
//	hero->setSpeedAndDirection(hero->getMovementSpeed(), Vec2(xAxist, yAxist));
//}
//
//void RunState::onKeyReleased(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
//{
//}
//
//void RunState::onMouseDown(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event)
//{
//}
//
//void RunState::onMouseUp(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event)
//{
//}
//
//void RunState::onMouseMove(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event)
//{
//}
//
//#pragma endregion
#pragma region BaseState

HeroBaseState::HeroBaseState()
{
	this->input->setKeyUp(EventKeyboard::KeyCode::KEY_W);
	this->input->setKeyDown(EventKeyboard::KeyCode::KEY_S);
	this->input->setKeyLeft(EventKeyboard::KeyCode::KEY_A);
	this->input->setKeyRight(EventKeyboard::KeyCode::KEY_D);
}

HeroBaseState::~HeroBaseState()
{
}

void HeroBaseState::setHeroClasses(HeroClasses _hero)
{
	this->heroClass = _hero;
}

void HeroBaseState::setHero(Hero* _hero)
{
    this->hero = _hero;
}

#pragma endregion

#pragma region IdleState
HeroIdleState::HeroIdleState()
{
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
	switch (this->heroClass)
	{
    case HeroClasses::Elf_M:
        this->hero->setAnimation(REPEAT::FOREVER, ELF_M_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Elf_F:

        this->hero->setAnimation(REPEAT::FOREVER, ELF_F_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Knight_M:

        this->hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_IDLE, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Knight_F:

        this->hero->setAnimation(REPEAT::FOREVER, KNIGHT_F_IDLE, frameBegin, frameEnd, frameDelay);
        break;
	}
}

HeroIdleState::~HeroIdleState()
{
}

void HeroIdleState::onKeyPressed(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    EventKeyboard* e = (EventKeyboard*)event;
    stateManager->switchState((HeroRunState*)stateManager->runState);
    if (keycode == this->input->getKeyUp())
    {
        yAxist++;
    }
    if (keycode == this->input->getKeyDown())
    {
        yAxist--;
    }
    if (keycode == this->input->getKeyLeft())
    {
        xAxist--;
        hero->setFlippedX(true);
    }
    if (keycode == this->input->getKeyRight())
    {
        xAxist++;
        hero->setFlippedX(false);
    }
    hero->setSpeedAndDirection(hero->getMovementSpeed(), Vec2(xAxist, yAxist));
}

void HeroIdleState::onKeyReleased(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
}

void HeroIdleState::onMouseDown(float xAxist, float yAxist, cocos2d::Event* event)
{
}

void HeroIdleState::onMouseUp(float xAxist, float yAxist, cocos2d::Event* event)
{
}

void HeroIdleState::onMouseMove(float xAxist, float yAxist, cocos2d::Event* event)
{
}

void HeroIdleState::update(float dt)
{
}

#pragma endregion

#pragma region RunState

HeroRunState::HeroRunState()
{
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    switch (this->heroClass)
    {
    case HeroClasses::Elf_M:
        this->hero->setAnimation(REPEAT::FOREVER, ELF_M_RUN, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Elf_F:

        this->hero->setAnimation(REPEAT::FOREVER, ELF_F_RUN, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Knight_M:

        this->hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_RUN, frameBegin, frameEnd, frameDelay);
        break;
    case HeroClasses::Knight_F:

        this->hero->setAnimation(REPEAT::FOREVER, KNIGHT_F_RUN, frameBegin, frameEnd, frameDelay);
        break;
    }
}

HeroRunState::~HeroRunState()
{
}

void HeroRunState::onKeyPressed(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
}

void HeroRunState::onKeyReleased(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
}

void HeroRunState::onMouseDown(float xAxist, float yAxist, cocos2d::Event* event)
{
}

void HeroRunState::onMouseUp(float xAxist, float yAxist, cocos2d::Event* event)
{
}

void HeroRunState::onMouseMove(float xAxist, float yAxist, cocos2d::Event* event)
{
}

void HeroRunState::update(float dt)
{
}
#pragma endregion

