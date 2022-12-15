#ifndef __HERO_H__
#define __HERO_H__
#include "Entity.h"
#include "HeroState.h"
enum class Gender
{
	Male,
	Female
};
enum class HeroJob
{
	Elf_M,
	Elf_F,
	Knight_M,
	Knight_F,
	Lizard_M,
	Lizard_F,
	Wizard_M,
	Wizard_F
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

