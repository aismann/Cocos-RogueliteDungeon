#ifndef __BOSS_ZOMBIE_PUNCH_H__
#define __BOSS_ZOMBIE_PUNCH_H__
#include "WeaponSkill.h"

class BossZombiePunch:public WeaponSkill
{
public:
	BossZombiePunch();
	~BossZombiePunch();
	void setLifeTime(float life);
	float getLifeTime();
	float lifeTimeCouting(float dt);
	void setDamage(float value);
	float getDamage();
private:
	float lifeTime;
};
#endif // !__SWORD_SLASH_H__

