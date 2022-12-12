//#ifndef __HERO_STATE_H__
//#define __HERO_STATE_H__
//
//#include "InputManager.h"
//#include "BaseState.h"
//#include "Hero.h"
//
//enum State
//{
//	Idle,
//	Run
//};
//
//class Hero;
//class HeroState
//{
//private:
//	float directX = 0, directY = 0;
//
//	State state = State::Idle;
//	InputManager* input = Singleton<InputManager>::getIntsance();
//	std::list<cocos2d::EventKeyboard::KeyCode> keyList;
//
//	void setIdleAnimation(Hero* hero);
//	void setRunAnimation(Hero* hero);
//
//	void checkIdleKeyPressed(Hero* hero);
//	void checkRunKeyPressed(Hero* hero);
//
//	void checkIdleKeyReleased(Hero* hero);
//	void checkRunKeyReleased(Hero* hero);
//
//	void onIdleKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//	void onRunKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//
//	void onIdleKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//	void onRunKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//public:
//	void switchState(State _state);
//
//	void onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//	void onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//
//	void onMouseDown(Hero* hero, cocos2d::Event* event);
//	void onMouseUp(Hero* hero, cocos2d::Event* event);
//	void onMouseMove(Hero* hero, cocos2d::Event* event);
//
//	void update(Hero* hero, float dt);
//};
//#endif // !__HERO_STATE_H__

#include <vector>
#include "cocos2d.h"
#include "InputManager.h"
#include "BaseState.h"
#include "Hero.h"
#ifndef __HERO_BASE_STATE_H__
#define __HERO_BASE_STATE_H__
class Hero;
class HeroBaseState:public BaseState<Hero,HeroBaseState>
{
protected:
	bool isMovement = false;
	static float x_axist;
	static float y_axist;
	static std::vector<cocos2d::EventKeyboard::KeyCode> keyList;
	std::vector<cocos2d::EventKeyboard::KeyCode>::iterator it;
	InputManager* input = Singleton<InputManager>::getIntsance();
public:
	virtual HeroBaseState* onStart(Hero* _entity) = 0;
	virtual HeroBaseState* onExit(Hero* _entity) = 0;
	virtual HeroBaseState* onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual HeroBaseState* onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual HeroBaseState* update(Hero* _entity, float dt) = 0;
};
#endif // !__HERO_STATE_H__

#ifndef __HERO_IDLE_STATE_H__
#define __HERO_IDLE_STATE_H__
class HeroBaseState;
class HeroIdleState :public HeroBaseState
{
public:
	HeroBaseState* onStart(Hero* _entity);
	HeroBaseState* onExit(Hero* _entity);
	HeroBaseState* onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* update(Hero* _entity, float dt);
};
#endif // !__HERO_IDLE_STATE_H__

#ifndef __HERO_RUN_STATE_H__
#define __HERO_RUN_STATE_H__
class HeroBaseState;
class HeroRunState :public HeroBaseState
{
public:
	HeroBaseState* onStart(Hero* _entity);
	HeroBaseState* onExit(Hero* _entity);
	HeroBaseState* onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* update(Hero* _entity, float dt);
};
#endif // !__HERO_RUN_STATE_H__

#ifndef __HERO_STATE_H__
#define __HERO_STATE_H__
class HeroState
{
private:
	HeroBaseState* activeState = new HeroIdleState();
public:
	void changeState(Hero* _entity, HeroBaseState* newState);
	void onKeyPressed(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(Hero* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void update(Hero* _entity, float dt);
};
#endif // !__HERO_STATE_H__

