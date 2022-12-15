#ifndef __WIZARD_H__
#define __WIZARD_H__
#include "Hero.h"
class Wizard:public Hero
{
protected:
	void initHero();
public:
	Wizard(Gender gen);
	~Wizard();
	float getHealth();
	float getMana();
	float getDamage();
	float getMovementSpeed();
};

#endif // !__WIZARD_H__

