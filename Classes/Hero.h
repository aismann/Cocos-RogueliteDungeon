#ifndef __HERO_H__
#define __HERO_H__
#include "Entity.h"
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
	HeroJob heroJob;
	EntityStats health;
	EntityStats mana;
	EntityStats damage;
	EntityStats movementSpeed;
	virtual void initHero();
public:
	Hero();
	~Hero();
	HeroJob getHeroJob();
	virtual float getHealth();
	virtual float getMana();
	virtual float getDamage();
	virtual float getMovementSpeed();
};
#endif // !__HERO_H__

