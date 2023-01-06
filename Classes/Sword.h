#ifndef __SWORD_H__
#define __SWORD_H__
#include "Weapon.h"
#include "ObjectPool.h"
#include "SwordSlash.h"
class Sword:public Weapon
{
protected:
	void initWeapon();
public:
	Sword();
	~Sword();
	void PrimarySkill(cocos2d::Sprite* weaponnode);
	void update(float dt);
private:
	ObjectPool<SwordSlash> slashPool;
	std::list<SwordSlash*> slashList;
	void addToPool(SwordSlash* slash);
	SwordSlash* slash;
};
#endif // !__ANIME_SWORD_H__

