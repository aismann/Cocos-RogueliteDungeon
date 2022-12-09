#ifndef __HERO_STATE_H__
#define __HERO_STATE_H__
#include "cocos2d.h"
#include "Hero.h"
#include "InputManager.h"
#include "HeroStateManager.h"
//
//#pragma region HEROSTATE
//class HeroState
//{
//protected:
//	InputManager* input = Singleton<InputManager>::getIntsance();
//public:
//	static IdleState idle;
//	static RunState run;
//	HeroState();
//	virtual ~HeroState() {};
//	virtual void onKeyPressed(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {};
//	virtual void onKeyReleased(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {};
//	virtual void onMouseDown(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event) {};
//	virtual void onMouseUp(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event) {};
//	virtual void onMouseMove(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event) {};
//	virtual void update(Hero* hero, float dt);
//};
//#pragma endregion
//
//#pragma region IDLE
//class IdleState :public HeroState
//{
//protected:
//
//public:
//	IdleState();
//	~IdleState();
//	virtual void onKeyPressed(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//	virtual void onKeyReleased(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//	virtual void onMouseDown(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event);
//	virtual void onMouseUp(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event);
//	virtual void onMouseMove(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event);
//};
//#pragma endregion
//
//#pragma region RUN
//class RunState :public HeroState
//{
//protected:
//
//public:
//	RunState();
//	~RunState();
//	virtual void onKeyPressed(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//	virtual void onKeyReleased(Hero* hero, float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
//	virtual void onMouseDown(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event);
//	virtual void onMouseUp(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event);
//	virtual void onMouseMove(Hero* hero, float xAxist, float yAxist, cocos2d::Event* event);
//};
//#pragma endregion

#pragma region BaseState
class HeroBaseState
{
protected:
	InputManager* input = Singleton<InputManager>::getIntsance();
	HeroClasses heroClass;
	Hero* hero;
	HeroStateManager* stateManager = Singleton<HeroStateManager>::getIntsance();
public:
	HeroBaseState();
	~HeroBaseState();
	void setHeroClasses(HeroClasses _hero);
	void setHero(Hero* _hero);
	virtual void onKeyPressed(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {};
	virtual void onKeyReleased(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) {};
	virtual void onMouseDown(float xAxist, float yAxist, cocos2d::Event* event) {};
	virtual void onMouseUp(float xAxist, float yAxist, cocos2d::Event* event) {};
	virtual void onMouseMove(float xAxist, float yAxist, cocos2d::Event* event) {};
	virtual void update(float dt) {};
};
#pragma endregion


#pragma region IdleState
class HeroIdleState:public HeroBaseState
{
protected:

public:
	HeroIdleState();
	~HeroIdleState();
	void onKeyPressed(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onMouseDown(float xAxist, float yAxist, cocos2d::Event* event);
	void onMouseUp(float xAxist, float yAxist, cocos2d::Event* event);
	void onMouseMove(float xAxist, float yAxist, cocos2d::Event* event);
	void update(float dt);

};
#pragma endregion

#pragma region RunState
class HeroRunState :public HeroBaseState
{
protected:

public:
	HeroRunState();
	~HeroRunState();
	void onKeyPressed(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(float xAxist, float yAxist, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onMouseDown(float xAxist, float yAxist, cocos2d::Event* event);
	void onMouseUp(float xAxist, float yAxist, cocos2d::Event* event);
	void onMouseMove(float xAxist, float yAxist, cocos2d::Event* event);
	void update(float dt);

};
#pragma endregion
#endif // !__HERO_STATE_H__

