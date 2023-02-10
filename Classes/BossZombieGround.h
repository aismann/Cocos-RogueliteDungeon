#ifndef __BOSS_ZOMBIE_GROUND_H__
#define __BOSS_ZOMBIE_GROUND_H__
#include "WeaponSkill.h"

class BossZombieGround:public WeaponSkill
{
public:
	BossZombieGround();
	~BossZombieGround();
	void setLifeTime(float life);
	float getLifeTime();
	float lifeTimeCouting(float dt);
	void setDamage(float value);
	float getDamage();
private:
	float lifeTime;
};
#endif // !__SWORD_SLASH_H__

