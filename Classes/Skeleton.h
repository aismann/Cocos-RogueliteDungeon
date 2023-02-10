#ifndef _SKELETON_H__
#define _SKELETON_H__
#include "Enemy.h"
#include "ObjectPool.h"
#include "SkeletonSlash.h"
class Skeleton:public Enemy
{
public:
	Skeleton();
	~Skeleton();
	void takeDamage(float damage);
	void entityIdle();
	void entityRun();
	void entityAttack(std::function<void()> onFinish);
	void entityShoot(std::function<void()> onFinish);
	void entityBehavior(float dt);
	void entityDie();
	void setIsEntityTakeDamage(bool value);
	bool getIsEntityTakeDamage();
	void setIsEntityRun(bool value);
	bool getIsEntityRun();
	void attacking();
	void shooting();
	void update(float dt);
private:
	ObjectPool<SkeletonSlash> slashPool;
	std::list<SkeletonSlash*> slashList;
	void addToPool(SkeletonSlash* slash);
	SkeletonSlash* slash;

};
#endif // !_SKELETON_H__

