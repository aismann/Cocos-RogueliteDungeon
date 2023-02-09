#include "ChooseHeroScene.h"
#include "GameManager.h"
#include "GameScene.h"

USING_NS_CC;

void ChooseHeroScene::initTileMap(cocos2d::Vec2 position)
{
    this->restroom = TMXTiledMap::create("maps/beginroom.tmx");
    this->restroom->setPosition(Vec2(position.x*0.5,position.y*0.5));
    this->restroom->setAnchorPoint(Vec2(0.5,0.5));
    this->restroom->setScaleX(((30*16)/this->restroom->getContentSize().width)*2);
    this->restroom->setScaleY(((20*16)/this->restroom->getContentSize().height)*2);
    this->addChild(this->restroom,-1);
}

Scene* ChooseHeroScene::createScene()
{
    return ChooseHeroScene::create();
}

// on "init" you need to initialize your instance
bool ChooseHeroScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::initWithPhysics() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->initTileMap((Vec2)visibleSize);

    Singleton<GameManager>::getIntsance()->addScene(this);
    Singleton<GameManager>::getIntsance()->addVisibleSize(visibleSize);

    this->chooseHero();
    this->goDungeon();

    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scheduleUpdate();
    return true;
}

void ChooseHeroScene::update(float dt)
{
    this->jobNameLabel->setString(std::string(heroJob == HeroJob::Knight ? "Knight" : "Elf"));
}

void ChooseHeroScene::chooseHero()
{
    auto visibleSize = Singleton<GameManager>::getIntsance()->getVisibleSize();

    knightButton = new Entity();
    elfButton = new Entity();

    knightButton->setTag(KNIGHT_TAG);
    elfButton->setTag(ELF_TAG);

    knightButton->setSpriteFrame(KNIGHT_M_IDLE, 0);
    elfButton->setSpriteFrame(ELF_M_IDLE, 0);

    knightButton->getTexture()->setAliasTexParameters();
    elfButton->getTexture()->setAliasTexParameters();

    knightButton->setScale(2);
    elfButton->setScale(2);

    auto knightBody = knightButton->getPhysicsBody();
    auto elfBody = elfButton->getPhysicsBody();

    knightBody->setDynamic(false);
    elfBody->setDynamic(false);

    elfButton->setFlippedX(true);

    knightButton->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2));
    elfButton->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2));

    this->addChild(knightButton);
    this->addChild(elfButton);

    auto touchKnightListener = EventListenerTouchOneByOne::create();
    touchKnightListener->onTouchBegan = [this,knightButton = knightButton](Touch* touch, Event* event)
    {
        Vec2 touchPos = touch->getLocation();
        if (knightButton->getBoundingBox().containsPoint(touchPos))
        {
            //CCLOG("knight touched %s", "yes");
            heroJob = HeroJob::Knight;
            Singleton<HeroManager>::getIntsance()->setHeroJob(heroJob);
            this->goDungeonLayer->setVisible(true);
        }
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchKnightListener, knightButton);

    auto touchElfListener = EventListenerTouchOneByOne::create();
    touchElfListener->onTouchBegan = [this,elfButton = elfButton](Touch* touch, Event* event)
    {
        Vec2 touchPos = touch->getLocation();
        if (elfButton->getBoundingBox().containsPoint(touchPos))
        {
            //CCLOG("elf touched %s", "yes");
            heroJob = HeroJob::Elf;
            Singleton<HeroManager>::getIntsance()->setHeroJob(heroJob);
            this->goDungeonLayer->setVisible(true);
        }
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchElfListener, elfButton);

}

void ChooseHeroScene::goDungeon()
{
    auto visibleSize = Singleton<GameManager>::getIntsance()->getVisibleSize();
    this->goDungeonLayer = LayerColor::create(Color4B::GRAY);
    this->goDungeonLayer->setOpacity(100);
    this->goDungeonLayer->setContentSize(Size(200, 160));
    this->goDungeonLayer->setPosition(visibleSize / 2 - goDungeonLayer->getContentSize() / 2);
    this->goDungeonLayer->setVisible(false);

    this->addChild(goDungeonLayer);
    this->jobNameLabel = Label::createWithTTF(std::string(heroJob == HeroJob::Knight ? "Knight" : "Elf"), "fonts/dogicapixel.ttf", 25);
    this->jobNameLabel->setPosition(Vec2(this->goDungeonLayer->getContentSize().width*0.5,this->goDungeonLayer->getContentSize().height*0.85));
    this->goDungeonLayer->addChild(jobNameLabel);


    Vector<MenuItem*> menuItems = {
    MenuItemLabel::create(Label::createWithTTF("Play", "fonts/dogicapixel.ttf", 25)  , [=](Ref* sender) {
        auto gameScene = GameScene::create();
        Director::getInstance()->replaceScene(gameScene);
    }),
    MenuItemLabel::create(Label::createWithTTF("Back", "fonts/dogicapixel.ttf", 25)  , [=](Ref* sender) {
        this->goDungeonLayer->setVisible(false);
    }),
    };

    auto menu = Menu::createWithArray(menuItems);
    goDungeonLayer->addChild(menu);
    menu->alignItemsVerticallyWithPadding(25);
    menu->setPosition(Vec2(goDungeonLayer->getContentSize().width*0.5,goDungeonLayer->getContentSize().height*0.4));
}
