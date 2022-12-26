#include "cocos2d.h"
#include "BaseState.h"
#include "Hero.h"

#ifndef __HERO_ATTACK_STATE_H__
#define __HERO_ATTACK_STATE_H__
class HeroBaseState;
class HeroAttackState :public HeroBaseState
{
public:
	void onStart(Hero* hero);
	void onExit(Hero* hero);
	HeroBaseState* onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	HeroBaseState* onMouseDown(Hero* hero, cocos2d::Event* event);
	HeroBaseState* onMouseUp(Hero* hero, cocos2d::Event* event);
	HeroBaseState* onMouseMove(Hero* hero, cocos2d::Event* event);
	HeroBaseState* update(Hero* hero, float dt);
private:
	void setAttackAnimation(Hero* hero);
};
#endif // !__HERO_RUN_STATE_H__
