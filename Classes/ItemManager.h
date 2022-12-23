#ifndef __ITEM_MANAGER_H__
#define __ITEM_MANAGER_H__
#include "cocos2d.h"
#include "Singleton.h"
#include "Weapon.h"
#include "AnimeSword.h"
class ItemManager
{
private:
	friend class Singleton<ItemManager>;
	std::vector<Weapon*> weaponList;
	cocos2d::Scene* scene;
	cocos2d::Vec2 visibleSize;
public:
	void setScene(cocos2d::Scene* scene);
	cocos2d::Scene* getScene();
	void setVisibleSize(cocos2d::Vec2 visibleSize);
	cocos2d::Vec2 getVisibleSize();
	void addItem(Weapon* weapon);
	void removeItem(Weapon* weapon);
	std::vector<Weapon*> getItemList();
};
#endif // !__GAME_MANAGER_H__

