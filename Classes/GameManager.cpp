#include "GameManager.h"
USING_NS_CC;
Scene* GameManager::scene;
Size GameManager::visibleSize;
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
