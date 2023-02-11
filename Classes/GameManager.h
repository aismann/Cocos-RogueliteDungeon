#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__
#include "cocos2d.h"
#include "Singleton.h"
#include "Skeleton.h"
#include "BossZombie.h"
#include "Orc.h"

enum ENEMYTYPE
{
	SKELETON,
	ORC,
	BOSSZOMBIE
};

class GameManager
{
public:
	void addScene(cocos2d::Scene* scene);
	cocos2d::Scene* getScene();
	void addVisibleSize(cocos2d::Size& size);
	cocos2d::Size getVisibleSize();
	void spawnEnemies();
	void startGame();
	void endGame();
	void addDangerPoint(float value);
	void setDangetPoint(float value);
	float getDangerPoint();
	void resume();
	void pause();
	void update(float dt);
private:
	friend class Singleton<GameManager>;

	static float dangerPoint;

	static cocos2d::Scene* scene;
	static cocos2d::Size visibleSize;

	static  ObjectPool<Skeleton> skeletonPool;
	static std::list<Skeleton*> skeletonList;
	void addToPool(Skeleton* obj);
	static Skeleton* skeleton;

	static ObjectPool<Orc> orcPool;
	static std::list<Orc*> orcList;
	void addToPool(Orc* obj);
	static Orc* orc;

	static ObjectPool<BossZombie> bossZombiePool;
	static std::list<BossZombie*> bossZombieList;
	void addToPool(BossZombie* obj);
	static BossZombie* bossZombie;
};

#endif // !__GAME_MANAGER_H__

