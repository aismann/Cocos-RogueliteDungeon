#ifndef __HERO_MANAGER_H__
#define __HERO_MANAGER_H__

#include "Hero.h"
#include "Singleton.h"
#include "InputManager.h"
class HeroManager
{
private:
	friend class Singleton<HeroManager>;
	float xAxist,yAxist;
	Hero* hero;
	cocos2d::Vec2 lastMousePositon;
	InputManager* input = Singleton<InputManager>::getIntsance();
	void zeroAxist();
	void initListener();
public:
	HeroManager();
	~HeroManager();
	void spawnHero(HeroClasses classes, cocos2d::Vec2& position);
	Hero* getHero();
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onMouseDown(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);
	void onMouseMove(cocos2d:: Event * event);
	void update(float dt);
};
#endif // !__HERO_MANAGER_H__


