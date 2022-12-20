#ifndef __WEAPON_H__
#define __WEAPON_H__
#include "Entity.h"
class Weapon :public Entity
{
protected:
	EntityStats damage;
	EntityStats attackSpeed;
	virtual void initWeapon();
public:
	Weapon();
	~Weapon();
	virtual float getDamage();
	virtual float getAttackSpeed();
};
#endif // !__WEAPON_H__

