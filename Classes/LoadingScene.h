#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "cocos2d.h"
#include "PhysicsShapeCache.h"
#include "GameResources.h"
#include "Configs.h"
#include "Entity.h"
class LoadingScene : public cocos2d::Scene
{
private:
    int resourceLoaded = 0;
    std::vector<std::string> resourceList;
    void initLoading(Vec2 position);
    void initLoadingLabel(Vec2 position);
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(LoadingScene);
};

#endif // __HELLOWORLD_SCENE_H__
