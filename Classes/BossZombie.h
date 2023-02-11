#ifndef _BOSS_ZOMBIE_H__
#define _BOSS_ZOMBIE_H__
#include "Enemy.h"
#include "ObjectPool.h"
#include "BossZombiePunch.h"
#include "BossZombieGround.h"
#include "AudioEngine.h"
class BossZombie:public Enemy
{
public:
	BossZombie();
	~BossZombie();
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
	void bossSkill();
	void update(float dt);
	float getManaPoint();
	void addManaPoint(float value);
private:
	float manaPoint = 0;
	int sound;
	ObjectPool<BossZombiePunch> punchPool;
	std::list<BossZombiePunch*> punchList;
	void addToPool(BossZombiePunch* punch);
	BossZombiePunch* punch;

	ObjectPool<BossZombieGround> groundPool;
	std::list<BossZombieGround*> groundList;
	void addToPool(BossZombieGround* ground);
	BossZombieGround* ground;

	cocos2d::Sprite* hpBarBG;
	cocos2d::Sprite* hpBar;

	void updateHPBar(float dt);
};
#endif // !_SKELETON_H__

