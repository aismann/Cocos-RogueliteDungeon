#ifndef __SWORD_H__
#define __SWORD_H__
#include "Weapon.h"
#include "ObjectPool.h"
#include "SwordSlash.h"
#include "HeroManager.h"
class Sword :public Weapon
{
protected:

public:
	Sword();
	~Sword();
	void PrimarySkill(cocos2d::Sprite* weaponnode);
	void setIsAttack(bool isAttack);
	void update(float dt);
private:
	int sound;
	ObjectPool<SwordSlash> slashPool;
	std::list<SwordSlash*> slashList;
	void addToPool(SwordSlash* slash);
	SwordSlash* slash;
	HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
};
#endif // !__ANIME_SWORD_H__

