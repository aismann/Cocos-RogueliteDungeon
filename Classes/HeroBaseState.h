#include "cocos2d.h"
#include "BaseState.h"
#include "Hero.h"
#ifndef __HERO_BASE_STATE_H__
#define __HERO_BASE_STATE_H__
class Hero;
class HeroBaseState :public BaseState<Hero, HeroBaseState>
{
protected:
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
