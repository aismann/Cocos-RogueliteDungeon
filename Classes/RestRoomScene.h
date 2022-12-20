#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "HeroManager.h"
#include "cocos2d.h"

class RestRoomScene : public cocos2d::Scene
{
private:
    bool properties;
    int count = 0;
    cocos2d::Vec2 lastMousePositon;
    cocos2d::TMXTiledMap* restroom;
    HeroManager* hero = Singleton<HeroManager>::getIntsance();
    void initTileMap(cocos2d::Vec2 position);
    cocos2d::Vec2 tileCoordForPosition(cocos2d::Vec2 position);
public:
    static cocos2d::Scene* createScene();
    bool onContactBegin(cocos2d::PhysicsContact& _contact);
    void onContactSeparate(cocos2d::PhysicsContact& _contact);
    void onMouseMove(cocos2d::Event* event);
    virtual bool init();
    void update(float dt);
    CREATE_FUNC(RestRoomScene);
};

#endif // __HELLOWORLD_SCENE_H__
