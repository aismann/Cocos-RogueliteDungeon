#include <vector>
#include "cocos2d.h"
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
	cocos2d::Vec2 lastMousePositon;
	float degree = 0;
	static std::vector<cocos2d::EventKeyboard::KeyCode> keyList;
	static std::vector<cocos2d::EventKeyboard::KeyCode>::iterator it;
public:
	virtual void onStart(Hero* hero) = 0;
	virtual void onExit(Hero* hero) = 0;
	virtual HeroBaseState* onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual HeroBaseState* onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual HeroBaseState* onMouseDown(Hero* hero, cocos2d::Event* event) = 0;
	virtual HeroBaseState* onMouseUp(Hero* hero, cocos2d::Event* event) = 0;
	virtual HeroBaseState* onMouseMove(Hero* hero, cocos2d::Event* event) = 0;
	virtual HeroBaseState* update(Hero* hero, float dt) = 0;
};
#endif // !__HERO_STATE_H__

#ifndef __HERO_IDLE_STATE_H__
#define __HERO_IDLE_STATE_H__
class HeroBaseState;
class HeroIdleState :public HeroBaseState
{
public:
	static void setIdleAnimation(Hero* hero);
	void onStart(Hero* hero);
	void onExit(Hero* hero);
	HeroBaseState* onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onMouseDown(Hero* hero, cocos2d::Event* event);
	HeroBaseState* onMouseUp(Hero* hero, cocos2d::Event* event);
	HeroBaseState* onMouseMove(Hero* hero, cocos2d::Event* event);
	HeroBaseState* update(Hero* hero, float dt);
};
#endif // !__HERO_IDLE_STATE_H__

#ifndef __HERO_RUN_STATE_H__
#define __HERO_RUN_STATE_H__
class HeroBaseState;
class HeroRunState :public HeroBaseState
{
public:
	static void setRunAnimation(Hero* hero);
	void onStart(Hero* hero);
	void onExit(Hero* hero);
	HeroBaseState* onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onMouseDown(Hero* hero, cocos2d::Event* event);
	HeroBaseState* onMouseUp(Hero* hero, cocos2d::Event* event);
	HeroBaseState* onMouseMove(Hero* hero, cocos2d::Event* event);
	HeroBaseState* update(Hero* hero, float dt);
};
#endif // !__HERO_RUN_STATE_H__

#ifndef __HERO_STATE_H__
#define __HERO_STATE_H__
class HeroState
{
private:
	HeroBaseState* activeState = new HeroIdleState();
public:
	void changeState(Hero* hero, HeroBaseState* newState);
	void onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onMouseDown(Hero* hero, cocos2d::Event* event);
	void onMouseUp(Hero* hero, cocos2d::Event* event);
	void onMouseMove(Hero* hero, cocos2d::Event* event);
	void update(Hero* hero, float dt);
};
#endif // !__HERO_STATE_H__

