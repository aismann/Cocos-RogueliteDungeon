#ifndef __WEAPON_SKILL_H__
#define __WEAPON_SKILL_H__
#include "Entity.h"
class WeaponSkill:public Entity
{
public:
	WeaponSkill();
	~WeaponSkill();
	virtual void setLifeTime(float life);
	virtual float getLifeTime();
	virtual float lifeTimeCouting(float dt);
	virtual void setDamage(float value);
	virtual float getDamage();
	virtual void takeHit();
private:
	float lifeTime;
	float damage;
};
#endif // !__WEAPON_SKILL_H__

