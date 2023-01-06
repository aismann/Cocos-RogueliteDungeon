#ifndef __HERO_MANAGER_H__
#define __HERO_MANAGER_H__

#include "Singleton.h"
#include "Elf.h"
#include "Knight.h"
#include "Lizard.h"
#include "Wizard.h"
class Hero;
class HeroManager
{
private:
	friend class Singleton<HeroManager>;

	cocos2d::Scene* scene;

	Hero* hero;

	//cocos2d::Sprite* weaponNode;

	cocos2d::Vec2 lastMousePositon;
	cocos2d::Vec2 visibleSize;
public:
	HeroManager();
	~HeroManager();

	void setScene(cocos2d::Scene* scene);

	void spawnHero(HeroJob heroJob, cocos2d::Vec2& position);

	Hero* getHero();

	//cocos2d::Node* getWeaponNode();

	void update(float dt);
};
#endif // !__HERO_MANAGER_H__


