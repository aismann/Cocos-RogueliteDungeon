#ifndef __HERO_STATE_H__
#define __HERO_STATE_H__

#include "InputManager.h"
#include "BaseState.h"
#include "Hero.h"

enum State
{
	Idle,
	Run
};

class Hero;
class HeroState
{
private:
	float directX = 0, directY = 0;

	State state = State::Idle;
	InputManager* input = Singleton<InputManager>::getIntsance();
	std::list<cocos2d::EventKeyboard::KeyCode> keyList;

	void setIdleAnimation(Hero* hero);
	void setRunAnimation(Hero* hero);

	void checkIdleKeyPressed(Hero* hero);
	void checkRunKeyPressed(Hero* hero);

	void checkIdleKeyReleased(Hero* hero);
	void checkRunKeyReleased(Hero* hero);

	void onIdleKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onRunKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	void onIdleKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onRunKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
public:
	void switchState(State _state);

	void onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	void onMouseDown(Hero* hero, cocos2d::Event* event);
	void onMouseUp(Hero* hero, cocos2d::Event* event);
	void onMouseMove(Hero* hero, cocos2d::Event* event);

	void update(Hero* hero, float dt);
};
#endif // !__HERO_STATE_H__

