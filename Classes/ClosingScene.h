#ifndef __CLOSE_SCENE_H__
#define __CLOSE_SCENE_H__
#include "GameManager.h"
#include "HeroManager.h"
#include "cocos2d.h"
class ClosingScene : public cocos2d::Scene
{
private:
    cocos2d::Node* expUI;
    void initInfo();
    void initMenu();
    GameManager* gameManager = Singleton<GameManager>::getIntsance();
    HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(ClosingScene);
};

#endif // __HELLOWORLD_SCENE_H__
