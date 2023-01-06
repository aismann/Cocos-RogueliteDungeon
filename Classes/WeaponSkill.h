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

	virtual float getDamage();
private:
	float lifeTime;
};
#endif // !__WEAPON_SKILL_H__

