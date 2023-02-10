#ifndef __SKELETON_SLASH_H__
#define __SKELETON_SLASH_H__
#include "WeaponSkill.h"

class SkeletonSlash:public WeaponSkill
{
public:
	SkeletonSlash();
	~SkeletonSlash();
	void setLifeTime(float life);
	float getLifeTime();
	float lifeTimeCouting(float dt);
	void setDamage(float value);
	float getDamage();
private:
	float lifeTime;
};
#endif // !__SWORD_SLASH_H__

