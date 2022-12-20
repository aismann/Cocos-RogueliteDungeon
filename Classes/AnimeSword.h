#ifndef __ANIME_SWORD_H__
#define __ANIME_SWORD_H__
#include "Weapon.h"
class AnimeSword:public Weapon
{
protected:
	void initWeapon();
public:
	AnimeSword();
	~AnimeSword();
	float getDamage();
	float getAttackSpeed();
};
#endif // !__ANIME_SWORD_H__

