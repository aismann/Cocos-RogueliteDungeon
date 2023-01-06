#ifndef __SWORD_SLASH_H__
#define __SWORD_SLASH_H__
#include "WeaponSkill.h"

class SwordSlash:public WeaponSkill
{
public:
	SwordSlash();
	~SwordSlash();
	void setLifeTime(float life);
	float getLifeTime();
	float lifeTimeCouting(float dt);

	float getDamage();
private:
	float lifeTime;
};
#endif // !__SWORD_SLASH_H__

