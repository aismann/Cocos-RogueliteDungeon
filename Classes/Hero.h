#ifndef __HERO_H__
#define __HERO_H__
#include "Entity.h"
#include "ItemManager.h"
#include "HeroBaseState.h"
enum class HeroJob
{
	None =-1,
	Elf,
	Knight,
	Lizard,
	Wizard
};
class Hero:public Entity
{
protected:
	bool is = false;
	HeroJob heroJob;

	EntityStats health;
	EntityStats shield;
	EntityStats damage;
	EntityStats movementSpeed;
	EntityStats pickupRange;

	ItemManager* itemManager;
	std::vector<Weapon*> weaponSlot;
	cocos2d::Sprite* weaponNode;

	HeroBaseState* activeState;
	void changeState(HeroBaseState* newState);
	virtual void initListener();
	virtual void initHero();
public:
	Hero();
	~Hero();
	HeroJob getHeroJob();

	virtual float getHealth();
	virtual float getShield();
	virtual float getDamage();
	virtual float getMovementSpeed();
	float getPickupRange();

	void pickupWeapon();
	void dropWeapon();
	void rotateWeaponbyCursor(cocos2d::Vec2 location);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

	void onMouseDown(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);
	void onMouseMove(cocos2d::Event* event);

	void update(float dt);
};
#endif // !__HERO_H__

