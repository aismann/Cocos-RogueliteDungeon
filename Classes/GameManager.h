#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__
#include "cocos2d.h"
#include "Singleton.h"
class GameManager
{
public:
	void addScene(cocos2d::Scene* scene);
	cocos2d::Scene* getScene();
	void addVisibleSize(cocos2d::Size& size);
	cocos2d::Size getVisibleSize();
private:
	friend class Singleton<GameManager>;
	static cocos2d::Scene* scene;
	static cocos2d::Size visibleSize;
};

#endif // !__GAME_MANAGER_H__

