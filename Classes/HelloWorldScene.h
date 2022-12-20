#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "Entity.h"
#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
private:
    //HeroManager* hero = Singleton<HeroManager>::getIntsance();
public:
    static cocos2d::Scene* createScene();
    bool onContactBegin(cocos2d::PhysicsContact& _contact);
    void onContactSeparate(cocos2d::PhysicsContact& _contact);
    virtual bool init();
    void update(float dt);
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
