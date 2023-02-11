#ifndef __BOW_H__
#define __BOW_H__
#include "Weapon.h"
#include "ObjectPool.h"
#include "BowShot.h"
#include "HeroManager.h"
class Bow :public Weapon
{
protected:

public:
	Bow();
	~Bow();
	void PrimarySkill(cocos2d::Sprite* weaponnode);
	void setIsAttack(bool isAttack);
	void update(float dt);
private:
	int sound;
	ObjectPool<BowShot> shotPool;
	std::list<BowShot*> shotList;
	void addToPool(BowShot* shot);
	BowShot* shot;
	HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
};
#endif // !__ANIME_SWORD_H__

