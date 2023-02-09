#ifndef __CHOOSE_HERO_SCENE_H__
#define __CHOOSE_HERO_SCENE_H__
#include "HeroManager.h"
#include "cocos2d.h"
class ChooseHeroScene : public cocos2d::Scene
{
private:
    cocos2d::LayerColor* goDungeonLayer;
    cocos2d::Label* jobNameLabel;
    cocos2d::Vec2 lastMousePositon;
    cocos2d::TMXTiledMap* restroom;
    void initTileMap(cocos2d::Vec2 position);

    HeroJob heroJob;
    Entity* knightButton;
    Entity* elfButton;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float dt);

    void chooseHero();
    void goDungeon();

    CREATE_FUNC(ChooseHeroScene);
};

#endif // __HELLOWORLD_SCENE_H__
