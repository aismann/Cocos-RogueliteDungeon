#ifndef __HERO_MANAGER_H__
#define __HERO_MANAGER_H__

#include "Hero.h"
#include "Singleton.h"
#include "InputManager.h"
#include "HeroState.h"
class Hero;
class HeroManager
{
private:
	friend class Singleton<HeroManager>;
	bool isKeyPressed = false;
	InputManager* input = Singleton<InputManager>::getIntsance();
	HeroState* state = new HeroState();
	Hero* hero;
	cocos2d::Vec2 lastMousePositon;
	void initListener();
public:
	HeroManager();
	~HeroManager();
	void spawnHero(HeroJob heroJob, cocos2d::Vec2& position);
	Hero* getHero();
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onMouseDown(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);
	void onMouseMove(cocos2d:: Event * event);
	void update(float dt);
};
#endif // !__HERO_MANAGER_H__


