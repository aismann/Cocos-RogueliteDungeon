#ifndef __BOW_SHOT_H__
#define __BOW_SHOT_H__
#include "WeaponSkill.h"

class BowShot:public WeaponSkill
{
public:
	BowShot();
	~BowShot();
	void setLifeTime(float life);
	float getLifeTime();
	float lifeTimeCouting(float dt);

	void setDamage(float value);
	float getDamage();
private:
	float lifeTime;
};
#endif // !__SWORD_SLASH_H__

