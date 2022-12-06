#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "Entity.h"
#include "cocos2d.h"
class HelloWorld : public cocos2d::Scene
{
private:
    float fixedframe = 1.0f / 60.0f;
    float elapsedtime = 0.0f;
    Entity* entity;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void update(float dt);
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
