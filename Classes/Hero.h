#ifndef __HERO_H__
#define __HERO_H__
#include "Entity.h"
#include "HeroState.h"
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
private:
	HeroJob heroJob;
	EntityStats health_point;
	EntityStats mana_point;
	EntityStats damage_point;
	EntityStats movement_speed;
	void initHero();
public:
	Hero(HeroJob heroJob, cocos2d::Vec2& position);
	~Hero();
	HeroJob getHeroJob();
	float getHealthPoint();
	float getManaPoint();
	float getDamagePoint();
	float getMovementSpeed();
};
#endif // !__HERO_H__

