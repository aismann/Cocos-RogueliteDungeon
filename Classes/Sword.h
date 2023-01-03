#ifndef __SWORD_H__
#define __SWORD_H__
#include "Weapon.h"
class Sword:public Weapon
{
protected:
	void initWeapon();
public:
	Sword();
	~Sword();
	float getDamage();
	float getAttackSpeed();
	void primaryAttack();
	void update(float dt);
};
#endif // !__ANIME_SWORD_H__

