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
	static std::vector<cocos2d::EventKeyboard::KeyCode> keyList;
	static std::vector<cocos2d::EventKeyboard::KeyCode>::iterator it;
public:
	virtual void onStart(Hero* _entity) = 0;
	virtual void onExit(Hero* _entity) = 0;
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
	static void setIdleAnimation(Hero* _entity);
	void onStart(Hero* _entity);
	void onExit(Hero* _entity);
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
	static void setRunAnimation(Hero* _entity);
	void onStart(Hero* _entity);
	void onExit(Hero* _entity);
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

