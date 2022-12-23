#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "Hero.h"
class Knight:public Hero
{
protected:
	void initHero();
public:
	Knight();
	~Knight();
	float getHealth();
	float getShield();
	float getDamage();
	float getMovementSpeed();
};
#endif // !__KNIGHT_H__

