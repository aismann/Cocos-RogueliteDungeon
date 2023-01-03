#ifndef __WEAPON_H__
#define __WEAPON_H__
#include "Entity.h"
class Weapon :public Entity
{
private:
protected:
	bool primaryAttacking;
	bool primaryAttackFinished;
	float weaponDegree;
	EntityStats damage;
	EntityStats attackSpeed;
	virtual void initWeapon();
public:
	Weapon();
	~Weapon();
	virtual float getDamage();
	virtual float getAttackSpeed();
	virtual void lightAttack();
	bool isPrimaryAttacking();
	virtual void update(float dt);
};
#endif // !__WEAPON_H__

