#ifndef __WEAPON_H__
#define __WEAPON_H__
#include "Entity.h"
class Weapon :public Entity
{
private:
protected:
	bool primarySkill;
	bool primaryFinished;
	float timeElapsed;
	virtual void initWeapon();
public:
	Weapon();
	~Weapon();
	virtual void PrimarySkill(cocos2d::Sprite* weaponnode) = 0;
	bool isPrimarySkillActive();
	virtual void setIsAttack(bool isAttack) = 0;
	virtual void update(float dt);
};
#endif // !__WEAPON_H__

