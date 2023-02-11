#ifndef _ORC_H__
#define _ORC_H__
#include "Enemy.h"
#include "ObjectPool.h"
#include "OrcMagic.h"
#include "AudioEngine.h"
class Orc:public Enemy
{
public:
	Orc();
	~Orc();
	void setEnemyAlived();
	void takeDamage(float damage);
	void entityIdle();
	void entityRun();
	void entityAttack(std::function<void()> onFinish);
	void entitySkill(std::function<void()> onFinish);
	void entityBehavior(float dt);
	void entityDie();
	void setIsEntityTakeDamage(bool value);
	bool getIsEntityTakeDamage();
	void setIsEntityRun(bool value);
	bool getIsEntityRun();
	void attacking();
	void update(float dt);
private:
	int sound;
	ObjectPool<OrcMagic> magicPool;
	std::list<OrcMagic*> magicList;
	void addToPool(OrcMagic* magic);
	OrcMagic* magic;

};
#endif // !_SKELETON_H__

