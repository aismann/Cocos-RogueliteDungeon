#include "HeroManager.h"
USING_NS_CC;

HeroManager::HeroManager()
{
    this->scene = nullptr;
	this->hero = nullptr;
}

HeroManager::~HeroManager()
{
}

void HeroManager::setScene(cocos2d::Scene* scene)
{
	this->scene = scene;
}

void HeroManager::spawnHero(HeroJob heroJob, cocos2d::Vec2& position)
{
	switch (heroJob)
	{
	case HeroJob::Elf:
		this->hero = new Elf();
		break;
	case HeroJob::Knight:
		this->hero = new Knight();
		break;
	case HeroJob::Lizard:
		this->hero = new Lizard();
		break;
	case HeroJob::Wizard:
		this->hero = new Wizard();
		break;
	}

	this->hero->setPosition(position);
	this->scene->addChild(this->hero,1);
}

Hero* HeroManager::getHero()
{
	return this->hero;
}

void HeroManager::setHeroJob(HeroJob job)
{
	this->heroJob = job;
}

HeroJob HeroManager::getHeroJob()
{
	return this->heroJob;
}

void HeroManager::update(float dt)
{
	//log("[%f][%f]",lastMousePositon.x,lastMousePositon.y);
	this->hero->update(dt);
}
