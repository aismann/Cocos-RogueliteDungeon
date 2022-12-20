#ifndef __ELF_H__
#define __ELF_H__
#include "Hero.h"
class Elf:public Hero
{
protected:
	void initHero();
public:
	Elf();
	~Elf();
	float getHealth();
	float getMana();
	float getDamage();
	float getMovementSpeed();
};
#endif // !__ELF_H__


