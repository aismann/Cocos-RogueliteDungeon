#include "IntroScene.h"
#include "MenuScene.h"
USING_NS_CC;

Scene* IntroScene::createScene()
{
    return IntroScene::create();
}

// on "init" you need to initialize your instance
bool IntroScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto mouseListener = EventListenerMouse::create();
    mouseListener->onMouseDown = CC_CALLBACK_1(IntroScene::onMouseDown, this);

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);

    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(IntroScene::onKeyPressed, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("intro.png");
    background->setPosition(visibleSize / 2);
    background->setAnchorPoint(Vec2(0.5, 0.5));
    background->setContentSize(visibleSize);
    this->addChild(background);

    auto gameName = Label::createWithTTF("Roguelite Dungeon","fonts/dogicapixel.ttf",60);
    gameName->setTextColor(Color4B(248, 246, 194, 255));
    gameName->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.7));
    gameName->enableShadow(Color4B(249,248,217,255));
    gameName->enableOutline(Color4B::BLACK,1);
    gameName->setVisible(false);
    this->addChild(gameName);

    auto anyKey = Label::createWithTTF("[Press any key]", "fonts/dogicapixel.ttf", 40);
    anyKey->setTextColor(Color4B(248, 246, 194, 255));
    anyKey->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5));
    anyKey->enableShadow(Color4B(249, 248, 217, 255));
    anyKey->enableOutline(Color4B::BLACK, 1);
    anyKey->setVisible(false);
    this->addChild(anyKey);
    schedule([=](float dt) {
        if (delay >= maxDelay)
        {
            anyKey->setVisible(true);
            gameName->setVisible(true);
            changeScene = true;
            delay = 0;
        }
        else if (changeScene == false)
        {
            delay++;
        }
        }, 1.0, "updateIntroScene");

    return true;
}

void IntroScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    if (changeScene)
    {
        auto menuScene = MenuScene::createScene();
        Director::getInstance()->replaceScene(TransitionCrossFade::create(1.0, menuScene));
    }
}

void IntroScene::onMouseDown(cocos2d::Event* event)
{
    if (changeScene)
    {
        auto menuScene = MenuScene::createScene();
        Director::getInstance()->replaceScene(TransitionCrossFade::create(1.0, menuScene));
    }
}

