#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "HeroManager.h"
#include "cocos2d.h"
class HelloWorld : public cocos2d::Scene
{
private:
    HeroManager* hero = Singleton<HeroManager>::getIntsance();
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void update(float dt);
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
