#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "HeroManager.h"
#include "ItemManager.h"
#include "cocos2d.h"
class GameScene : public cocos2d::Scene
{
private:
    bool properties;
    int count = 0;
    bool m_contactStarted = false;
    cocos2d::Vec2 lastMousePositon;
    cocos2d::TMXTiledMap* restroom;
    HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
    void initTileMap(cocos2d::Vec2 position);

    cocos2d::Camera* cameraUI;
    void initCameraUI();
    void followHero();
public:
    static cocos2d::Scene* createScene();
    bool onContactBegin(cocos2d::PhysicsContact& _contact);
    void onContactSeparate(cocos2d::PhysicsContact& _contact);
    void onMouseMove(cocos2d::Event* event);
    virtual bool init();
    void update(float dt);
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
