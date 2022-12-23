#ifndef __LIZARD_H__
#define __LIZARD_H__
#include "Hero.h"
class Lizard:public Hero
{
protected:
	void initHero();
public:
	Lizard();
	~Lizard();
	float getHealth();
	float getShield();
	float getDamage();
	float getMovementSpeed();
};
#endif // !__LIZARD_H__

