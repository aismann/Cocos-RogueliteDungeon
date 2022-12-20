#include "MenuScene.h"
#include "AudioEngine.h"
#include "RestRoomScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto gameName = Label::createWithTTF("Roguelite Dungeon", "fonts/dogicapixel.ttf", 50);
    gameName->setTextColor(Color4B(248, 246, 194, 255));
    gameName->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.7));
    gameName->enableShadow(Color4B(249, 248, 217, 255));
    gameName->enableOutline(Color4B::BLACK, 1);
    this->addChild(gameName);

    this->soundOn = true;

    AudioEngine::preload("sounds/background.mp3", [&](bool isSuccess) {
        log("Preload background.pm3 %s", isSuccess ? "Success" : "Failed");
        if (isSuccess) {
            this->backgroundMusic = AudioEngine::play2d("sounds/background.mp3", true);
        }
    });
    if (!AudioEngine::isEnabled())
    {
        AudioEngine::stopAll();
        this->soundOn = !this->soundOn;
    }

    auto play = Label::createWithTTF("Play", "fonts/dogicapixel.ttf", 40);
    play->setTextColor(Color4B(248, 246, 194, 255));
    play->enableShadow(Color4B(249, 248, 217, 255));
    play->enableOutline(Color4B::BLACK, 1);

    this->soundLabel = Label::createWithTTF(std::string("Sound: ") + std::string(this->soundOn ? "ON" : "OFF"), "fonts/dogicapixel.ttf", 40);
    this->soundLabel->setTextColor(Color4B(248, 246, 194, 255));
    this->soundLabel->enableShadow(Color4B(249, 248, 217, 255));
    this->soundLabel->enableOutline(Color4B::BLACK, 1);

    auto quit = Label::createWithTTF("Quit", "fonts/dogicapixel.ttf", 40);
    quit->setTextColor(Color4B(248, 246, 194, 255));
    quit->enableShadow(Color4B(249, 248, 217, 255));
    quit->enableOutline(Color4B::BLACK, 1);

    Vector<MenuItem*> menuItems = {
        MenuItemLabel::create(play  , [=](Ref* sender) {
            auto restRoomScene = RestRoomScene::create();
            Director::getInstance()->replaceScene(restRoomScene);
        }),
        MenuItemLabel::create(this->soundLabel, [&](Ref* sender) {
            this->soundOn = !this->soundOn;
            AudioEngine::setEnabled(this->soundOn);
            this->soundLabel->setString(std::string("Sound: ") + std::string(this->soundOn ? "ON" : "OFF"));
            if (AudioEngine::isEnabled())
            {
                this->backgroundMusic = AudioEngine::play2d("sounds/background.mp3", true);
            }
            else
            {
                AudioEngine::stopAll();
            }
        }),
        MenuItemLabel::create(quit  , [=](Ref* sender) {
            Director::getInstance()->end();
        }),
    };
    auto menu = Menu::createWithArray(menuItems);
    addChild(menu);
    menu->alignItemsVerticallyWithPadding(20);
    menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    return true;
}

