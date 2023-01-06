#include "cocos2d.h"
#include "BaseState.h"
#include "Hero.h"

#ifndef __HERO_ATTACK_STATE_H__
#define __HERO_ATTACK_STATE_H__
class HeroBaseState;
class HeroAttackState :public HeroBaseState
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
	void setAttackAnimation();
};
#endif // !__HERO_RUN_STATE_H__
