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
	void onHeroDie();
};
#endif // !__ELF_H__


