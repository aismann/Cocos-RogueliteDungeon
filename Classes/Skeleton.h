#ifndef _SKELETON_H__
#define _SKELETON_H__
#include "Enemy.h"
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
	void entityBehavior();
	void entityDie();
	void setIsEntityTakeDamage(bool value);
	bool getIsEntityTakeDamage();
	void setIsEntityRun(bool value);
	bool getIsEntityRun();
	void attacking();
	void setIsEntityAttack(bool value);
	void shooting();
	void setIsEntityShooting(bool value);
	void update(float dt);
private:
};
#endif // !_SKELETON_H__

