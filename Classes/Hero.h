#ifndef __HERO_H__
#define __HERO_H__
#include "Entity.h"
#include "ItemManager.h"
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

	void update(float dt);
};
#endif // !__HERO_H__

