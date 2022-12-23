#include "ItemManager.h"
USING_NS_CC;
void ItemManager::setScene(cocos2d::Scene* scene)
{
	this->scene = scene;
}

cocos2d::Scene* ItemManager::getScene()
{
	return this->scene;
}

void ItemManager::setVisibleSize(cocos2d::Vec2 visibleSize)
{
	this->visibleSize = visibleSize;
}

cocos2d::Vec2 ItemManager::getVisibleSize()
{
	return this->visibleSize;
}

void ItemManager::addItem(Weapon* weapon)
{
	weaponList.push_back(weapon);
	this->scene->addChild(weapon);
}

void ItemManager::removeItem(Weapon* weapon)
{
	auto it = std::find(weaponList.begin(),weaponList.end(),weapon);
	if (it!= weaponList.end())
	{
		weaponList.erase(it);
		weapon->removeFromParentAndCleanup(true);
	}
}

std::vector<Weapon*> ItemManager::getItemList()
{
	return this->weaponList;
}
