#ifndef __ORC_MAGIC_H__
#define __ORC_MAGIC_H__
#include "WeaponSkill.h"

class OrcMagic:public WeaponSkill
{
public:
	OrcMagic();
	~OrcMagic();
	void setLifeTime(float life);
	float getLifeTime();
	float lifeTimeCouting(float dt);
	void setDamage(float value);
	float getDamage();
private:
	float lifeTime;
};
#endif // !__SWORD_SLASH_H__

