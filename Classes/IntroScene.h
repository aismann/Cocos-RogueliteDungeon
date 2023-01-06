#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"
class IntroScene : public cocos2d::Scene
{
private:
    bool changeScene = false;
    float delay = 0;
    float maxDelay = 0.5f;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onMouseDown(cocos2d::Event* event);
    CREATE_FUNC(IntroScene);
};

#endif // __HELLOWORLD_SCENE_H__
