#ifndef __HERO_H__
#define __HERO_H__
#include "Entity.h"
#include "HeroState.h"
enum class HeroClasses
{
	Elf_M,
	Elf_F,
	Knight_M,
	Knight_F,
	Lizard,
	Wizard
};
class Hero:public Entity
{
private:
	HeroClasses heroClass;
	EntityStats health_point;
	EntityStats mana_point;
	EntityStats damage_point;
	EntityStats movement_speed;
	void initHero();
public:
	Hero(HeroClasses classes, cocos2d::Vec2& position);
	~Hero();
	HeroClasses getHeroClass();
	float getHealthPoint();
	float getManaPoint();
	float getDamagePoint();
	float getMovementSpeed();
};
#endif // !__HERO_H__

