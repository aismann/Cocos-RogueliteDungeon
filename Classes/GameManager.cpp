#include "GameManager.h"
#include "HeroManager.h"
USING_NS_CC;
Scene* GameManager::scene;
Size GameManager::visibleSize;
float GameManager::dangerPoint = 100.f;

ObjectPool<Skeleton> GameManager::skeletonPool;
std::list<Skeleton*> GameManager::skeletonList;
Skeleton* GameManager::skeleton;

ObjectPool<Orc> GameManager::orcPool;
std::list<Orc*> GameManager::orcList;
Orc* GameManager::orc;

ObjectPool<BossZombie> GameManager::bossZombiePool;
std::list<BossZombie*> GameManager::bossZombieList;
BossZombie* GameManager::bossZombie;

void GameManager::addScene(cocos2d::Scene* scene)
{
	this->scene = scene;
}

cocos2d::Scene* GameManager::getScene()
{
	return this->scene;
}

void GameManager::addVisibleSize(cocos2d::Size& size)
{
	this->visibleSize = size;
}

cocos2d::Size GameManager::getVisibleSize()
{
	return this->visibleSize;
}

void GameManager::spawnEnemies()
{
	HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
	const int ENEMY_MAX_RAND = 1;
	const int ENEMY_MIN_RAND = 0;
	int enemyType = rand() % (ENEMY_MAX_RAND - ENEMY_MIN_RAND + 1) + ENEMY_MIN_RAND;

	const int MIN_X = -100;
	const int MAX_X = 100;

	const int MIN_Y = -100;
	const int MAX_Y = 100;

	float posX = rand() % (MAX_X - MIN_X + 1) + MIN_X;
	float posY = rand() % (MAX_Y - MIN_Y + 1) + MIN_Y;


	Vec2 direction = Vec2(posX, posY);
	direction.normalize();

	const int padding = -20;
	Vec2 position = direction * (GameManager::getVisibleSize().height / 2 + padding)
		+ GameManager::getVisibleSize() / 2;

	switch (enemyType)
	{
	case ENEMYTYPE::SKELETON:
		skeleton = skeletonPool.getOnce();
		skeleton->setEnemyAlived();
		skeleton->setPosition(position);
		GameManager::getScene()->addChild(skeleton);
		skeletonList.push_back(skeleton);
		break;
	case ENEMYTYPE::ORC:
		orc = orcPool.getOnce();
		orc->setEnemyAlived();
		orc->setPosition(position);
		GameManager::getScene()->addChild(orc);
		orcList.push_back(orc);
		break;
	default:
		skeleton = skeletonPool.getOnce();
		skeleton->setEnemyAlived();
		skeleton->setPosition(position);
		GameManager::getScene()->addChild(skeleton);
		skeletonList.push_back(skeleton);
		break;
	}

	if (dangerPoint >= 100)
	{
		bossZombie = bossZombiePool.getOnce();
		bossZombie->setEnemyAlived();
		bossZombie->setPosition(position);
		GameManager::getScene()->addChild(bossZombie);
		bossZombieList.push_back(bossZombie);
		dangerPoint = 0;
	}
}

void GameManager::startGame()
{
	srand(time(NULL));
	auto spawnEnemy = CallFunc::create([&]() {
		spawnEnemies();
		});
	auto sequence = Sequence::create(spawnEnemy, DelayTime::create(2.5f), nullptr);
	auto repeatSpawnEnemies = RepeatForever::create(sequence);
	scene->runAction(repeatSpawnEnemies);
}

void GameManager::endGame()
{
	scene->removeChildByTag(HERO_TAG);
	scene->removeChildByTag(ENEMY_TAG);
	scene->removeChildByTag(PLAYER_ATTACK_TAG);
	scene->removeChildByTag(ENEMY_ATTACK_TAG);
	scene = nullptr;
	skeletonPool.destroy();
	skeletonList.clear();
	orcPool.destroy();
	orcList.clear();
	bossZombiePool.destroy();
	bossZombieList.clear();
}

void GameManager::addDangerPoint(float value)
{
	if (dangerPoint >= 100.f)
	{
		dangerPoint = 100.f;
	}
	else
	{
		dangerPoint += value;
	}
}

void GameManager::setDangetPoint(float value)
{
	dangerPoint = value;
}

float GameManager::getDangerPoint()
{
	return dangerPoint;
}

void GameManager::addToPool(Skeleton* obj)
{
	skeletonPool.returnObject(obj);
}

void GameManager::addToPool(Orc* obj)
{
	orcPool.returnObject(obj);
}

void GameManager::addToPool(BossZombie* obj)
{
	bossZombiePool.returnObject(obj);
}

void GameManager::resume() {
	//GameManager::getScene()->resume();
	for each (auto child in GameManager::getScene()->getChildren())
	{
		if (child->getTag() == HERO_TAG)
		{
			child->resume();
			Hero* hero = (Hero*)child;
			hero->getPhysicsBody()->setVelocity(hero->getSpeed() * hero->getDirection());
		}
		if (child->getTag() == ENEMY_TAG)
		{
			child->resume();
			Enemy* enemy = (Enemy*)child;
			enemy->getPhysicsBody()->setVelocity(enemy->getSpeed() * enemy->getDirection());
		}
		if (child->getTag() == PLAYER_ATTACK_TAG)
		{
			child->resume();
			WeaponSkill* attack = (WeaponSkill*)child;
			attack->getPhysicsBody()->setVelocity(attack->getSpeed() * attack->getDirection());
		}
		if (child->getTag() == ENEMY_ATTACK_TAG)
		{
			child->resume();
			WeaponSkill* attack = (WeaponSkill*)child;
			attack->getPhysicsBody()->setVelocity(attack->getSpeed()*attack->getDirection());
		}
	}
}

void GameManager::pause() {
	//GameManager::getScene()->pause();
	for each (auto child in GameManager::getScene()->getChildren())
	{
		if (child->getTag() == HERO_TAG)
		{
			child->pause();
			Hero* hero = (Hero*)child;
			hero->getPhysicsBody()->setVelocity(Vec2::ZERO);
		}
		if (child->getTag() == ENEMY_TAG)
		{
			child->pause();
			Enemy* enemy = (Enemy*)child;
			enemy->getPhysicsBody()->setVelocity(Vec2::ZERO);
		}
		if (child->getTag() == PLAYER_ATTACK_TAG)
		{
			log("Found");
			child->pause();
			WeaponSkill* attack = (WeaponSkill*)child;
			attack->getPhysicsBody()->setVelocity(Vec2::ZERO);
		}
		if (child->getTag() == ENEMY_ATTACK_TAG)
		{
			child->pause();
			WeaponSkill* attack = (WeaponSkill*)child;
			attack->getPhysicsBody()->setVelocity(Vec2::ZERO);
		}
	}
}

void GameManager::update(float dt)
{
	std::list<Orc*>::iterator orcIt;
	std::list<Orc*> removeArrayOrc;
	for (orcIt = orcList.begin(); orcIt != orcList.end(); ++orcIt)
	{
		orc = *orcIt;
		//float life = orc->lifeTimeCouting(dt);

		if (orc->getIsDie() == true)
		{
			Singleton<GameManager>::getIntsance()->getScene()->removeChild(orc);
			removeArrayOrc.push_back(orc);
			addToPool(orc);
		}
	}
	for (orcIt = removeArrayOrc.begin(); orcIt != removeArrayOrc.end(); ++orcIt) {
		orcList.remove(*orcIt);
	}

	std::list<Skeleton*>::iterator skeletonIt;
	std::list<Skeleton*> removeArraySkeleton;
	for (skeletonIt = skeletonList.begin(); skeletonIt != skeletonList.end(); ++skeletonIt)
	{
		skeleton = *skeletonIt;
		//float life = skeleton->lifeTimeCouting(dt);

		if (skeleton->getIsDie() == true)
		{
			Singleton<GameManager>::getIntsance()->getScene()->removeChild(skeleton);
			removeArraySkeleton.push_back(skeleton);
			addToPool(skeleton);
		}
	}
	for (skeletonIt = removeArraySkeleton.begin(); skeletonIt != removeArraySkeleton.end(); ++skeletonIt) {
		skeletonList.remove(*skeletonIt);
	}

	std::list<BossZombie*>::iterator bossZombieIt;
	std::list<BossZombie*> removeArrayBossZombie;
	for (bossZombieIt = bossZombieList.begin(); bossZombieIt != bossZombieList.end(); ++bossZombieIt)
	{
		bossZombie = *bossZombieIt;
		//float life = bossZombie->lifeTimeCouting(dt);

		if (bossZombie->getIsDie() == true)
		{
			Singleton<GameManager>::getIntsance()->getScene()->removeChild(bossZombie);
			removeArrayBossZombie.push_back(bossZombie);
			addToPool(bossZombie);
		}
	}
	for (bossZombieIt = removeArrayBossZombie.begin(); bossZombieIt != removeArrayBossZombie.end(); ++bossZombieIt) {
		bossZombieList.remove(*bossZombieIt);
	}
}