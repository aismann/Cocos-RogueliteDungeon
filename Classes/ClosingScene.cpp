#include "ClosingScene.h"
#include "MenuScene.h"

USING_NS_CC;

void ClosingScene::initInfo()
{
    expUI = Node::create();
    expUI->setAnchorPoint(Vec2(0.5, 0.5));
    Label* expValue = Label::createWithTTF("0", "fonts/dogicapixel.ttf", 25);
    expValue->setName("expValue");
    expUI->addChild(expValue);
    expUI->setPosition(gameManager->getVisibleSize().width*0.5, gameManager->getVisibleSize().height*0.7);
    this->addChild(expUI);
    ((Label*)expValue)->setString(std::string("Your Score: ") + std::to_string(heroManager->getHero()->getScorePoint()));
}

void ClosingScene::initMenu()
{
    Vector<MenuItem*> menuItems = {
        MenuItemLabel::create(Label::createWithSystemFont("Return menu", "Arial", 40)  , [=](Ref* sender) {
            auto menuScene = MenuScene::create();
            Director::getInstance()->replaceScene(menuScene);
        }),
    };

    auto menu = Menu::createWithArray(menuItems);
    addChild(menu);
    menu->alignItemsVertically();
    menu->setPosition(gameManager->getVisibleSize()/2);
}

Scene* ClosingScene::createScene()
{
    return ClosingScene::create();
}

// on "init" you need to initialize your instance
bool ClosingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("closingbg.png");
    background->setPosition(visibleSize / 2);
    background->setAnchorPoint(Vec2(0.5, 0.5));
    background->setContentSize(visibleSize);
    this->addChild(background);

    initInfo();
    initMenu();
    gameManager->endGame();
    return true;
}

