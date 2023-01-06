#include "cocos2d.h"
#include "BaseState.h"
#include "Hero.h"
#ifndef __HERO_BASE_STATE_H__
#define __HERO_BASE_STATE_H__
class Hero;
class HeroBaseState :public BaseState<Hero, HeroBaseState>
{
protected:
	cocos2d::Vec2 lastMousePositon;
	static Hero* hero;
	static std::vector<cocos2d::EventKeyboard::KeyCode> keyList;
	static std::vector<cocos2d::EventKeyboard::KeyCode>::iterator keyIt;
	static std::vector<cocos2d::EventMouse::MouseButton> buttonList;
	static std::vector<cocos2d::EventMouse::MouseButton>::iterator buttonIt;
public:
	void addHero(Hero* hero);
	virtual void onStart() = 0;
	virtual void onExit() = 0;
	virtual HeroBaseState* onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual HeroBaseState* onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual HeroBaseState* onMouseDown(cocos2d::Event* event) = 0;
	virtual HeroBaseState* onMouseUp(cocos2d::Event* event) = 0;
	virtual HeroBaseState* onMouseMove(cocos2d::Event* event) = 0;
	virtual HeroBaseState* update(float dt) = 0;
};
#endif // !__HERO_STATE_H__
