#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "HeroManager.h"
#include "ItemManager.h"
#include "cocos2d.h"
class RestRoomScene : public cocos2d::Scene
{
private:
    bool properties;
    bool isGoDungeonLayerOpen = false;
    cocos2d::LayerColor* goDungeonLayer;
    int count = 0;
    bool m_contactStarted = false;
    cocos2d::Vec2 lastMousePositon;
    cocos2d::TMXTiledMap* restroom;
    HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
    void initTileMap(cocos2d::Vec2 position);

    cocos2d::Camera* cameraUI;
    void initCameraUI();
    void followHero();

    HeroJob heroJob;
    Entity* knightButton;
    Entity* elfButton;
public:
    static cocos2d::Scene* createScene();
    bool onContactBegin(cocos2d::PhysicsContact& _contact);
    void onContactSeparate(cocos2d::PhysicsContact& _contact);
    void onMouseMove(cocos2d::Event* event);
    virtual bool init();
    void update(float dt);

    void spawnHero(HeroJob job);
    void chooseHero();
    void goDungeon();

    CREATE_FUNC(RestRoomScene);
};

#endif // __HELLOWORLD_SCENE_H__
