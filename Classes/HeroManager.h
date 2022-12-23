#ifndef __HERO_MANAGER_H__
#define __HERO_MANAGER_H__

#include "Singleton.h"
#include "HeroState.h"
#include "Elf.h"
#include "Knight.h"
#include "Lizard.h"
#include "Wizard.h"
class Hero;
class HeroManager
{
private:
	friend class Singleton<HeroManager>;
	
	void initListener();

	cocos2d::Scene* scene;

	Hero* hero;

	HeroState* state;

	cocos2d::Sprite* weaponNode;

	cocos2d::Vec2 lastMousePositon;
	cocos2d::Vec2 visibleSize;
public:
	HeroManager();
	~HeroManager();

	void setScene(cocos2d::Scene* scene);
	void setVisibleSize(cocos2d::Vec2 visibleSize);
	cocos2d::Vec2 getVisibleSize();

	void spawnHero(HeroJob heroJob, cocos2d::Vec2& position);

	Hero* getHero();

	cocos2d::Node* getWeaponNode();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	void onMouseDown(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);
	void onMouseMove(cocos2d:: Event * event);

	void update(float dt);
};
#endif // !__HERO_MANAGER_H__


