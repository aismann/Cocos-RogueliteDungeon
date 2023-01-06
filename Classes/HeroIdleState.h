#include "cocos2d.h"
#include "BaseState.h"
#include "Hero.h"

#ifndef __HERO_IDLE_STATE_H__
#define __HERO_IDLE_STATE_H__
class HeroBaseState;
class HeroIdleState :public HeroBaseState
{
public:
	void onStart();
	void onExit();
	HeroBaseState* onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onMouseDown(cocos2d::Event* event);
	HeroBaseState* onMouseUp(cocos2d::Event* event);
	HeroBaseState* onMouseMove(cocos2d::Event* event);
	HeroBaseState* update(float dt);
private:
	void setIdleAnimation();
};
#endif // !__HERO_IDLE_STATE_H__