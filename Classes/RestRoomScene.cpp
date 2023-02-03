#include "RestRoomScene.h"
#include "PhysicsShapeCache.h"
#include "Sword.h"
#include "SwordSlash.h"
#include "GameManager.h"
#include "Enemy.h"

USING_NS_CC;

void RestRoomScene::initTileMap(cocos2d::Vec2 position)
{
    this->restroom = TMXTiledMap::create("maps/beginroom.tmx");
    this->restroom->setPosition(Vec2(position.x*0.5,position.y*0.5));
    this->restroom->setAnchorPoint(Vec2(0.5,0.5));
    this->restroom->setScaleX(((30*16)/this->restroom->getContentSize().width)*2);
    this->restroom->setScaleY(((20*16)/this->restroom->getContentSize().height)*2);
    this->addChild(this->restroom,-1);

    auto objectGroup = this->restroom->getObjectGroup("WallCollision");
    for (auto &object: objectGroup->getObjects())
    {
        auto properties = object.asValueMap();
        auto x = properties.at("x").asInt() + properties.at("width").asInt()/2;
        auto y = properties.at("y").asInt() + properties.at("height").asInt() / 2;
        auto objectSize = Size(properties.at("width").asInt(), properties.at("height").asInt());
        auto wallBody = PhysicsBody::createBox(objectSize, PhysicsMaterial(1.0f, 0.0f, 0.0f));
        wallBody->setDynamic(false);
        wallBody->setContactTestBitmask(0xffff);
        wallBody->setCategoryBitmask(64);
        wallBody->setContactTestBitmask(51);
        auto wallNode = Node::create();
        wallNode->setPosition(x, y);
        wallNode->setPhysicsBody(wallBody);
        wallNode->setContentSize(objectSize);
        this->restroom->addChild(wallNode,2);
    }
}

void RestRoomScene::initCameraUI()
{
    this->cameraUI = Camera::create();
    this->cameraUI->setCameraFlag(CameraFlag::USER1);
    this->addChild(cameraUI);
}

void RestRoomScene::followHero()
{
    auto camera = getDefaultCamera();
    Vec2 targetPos = this->heroManager->getHero()->getPosition();
    auto visibleSize = Singleton<GameManager>::getIntsance()->getVisibleSize();
    targetPos.x = clampf(targetPos.x, (visibleSize.width - (BOUNDING_BOX.width - visibleSize.width)) / 2, (visibleSize.width + (BOUNDING_BOX.width - visibleSize.width)) / 2);
    targetPos.y = clampf(targetPos.y, (visibleSize.height - (BOUNDING_BOX.height - visibleSize.height)) / 2, (visibleSize.height + (BOUNDING_BOX.height - visibleSize.height)) / 2);
    Vec2 currentPos = camera->getPosition();
    currentPos = currentPos.lerp(targetPos, 0.1);
    camera->setPosition(currentPos);
}


Scene* RestRoomScene::createScene()
{
    return RestRoomScene::create();
}

bool RestRoomScene::onContactBegin(cocos2d::PhysicsContact& _contact)
{
    if (m_contactStarted)
    {
        return true;
    }
    if ((_contact.getShapeA()->getCategoryBitmask() & _contact.getShapeB()->getCollisionBitmask()) <= 0 ||
        (_contact.getShapeB()->getCategoryBitmask() & _contact.getShapeA()->getCollisionBitmask()) <= 0)
    {
        return false;
    }

    auto nodeA = _contact.getShapeA()->getBody()->getNode();
    auto nodeB = _contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        int tagA = nodeA->getTag();
        int tagB = nodeB->getTag();
        if ((tagA == HERO_TAG && tagB == KNIGHT_TAG)
            || (tagB == HERO_TAG && tagA == KNIGHT_TAG))
        {
            log("KNIGHT TAG DETECTED");
        }
    }
    m_contactStarted = true;
    return true;
}

void RestRoomScene::onContactSeparate(cocos2d::PhysicsContact& _contact)
{
    auto nodeA = _contact.getShapeA()->getBody()->getNode();
    auto nodeB = _contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        //nodeA->setColor(Color3B::WHITE);
        //nodeB->setColor(Color3B::WHITE);
        m_contactStarted = false;
    }
}

void RestRoomScene::onMouseMove(cocos2d::Event* event)
{
    EventMouse* e = (EventMouse*)event;
    this->lastMousePositon = e->getLocationInView();

}

// on "init" you need to initialize your instance
bool RestRoomScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::initWithPhysics() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(RestRoomScene::onContactBegin, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(RestRoomScene::onContactSeparate, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    auto mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(RestRoomScene::onMouseMove, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);

    this->initCameraUI();
    this->initTileMap((Vec2)visibleSize);

    Singleton<GameManager>::getIntsance()->addScene(this);
    Singleton<GameManager>::getIntsance()->addVisibleSize(visibleSize);

    this->chooseHero();
    this->goDungeon();

    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scheduleUpdate();
    return true;
}

void RestRoomScene::update(float dt)
{
    //this->followHero();
    //heroManager->update(dt);
}

void RestRoomScene::spawnHero(HeroJob job)
{
    auto visibleSize = Singleton<GameManager>::getIntsance()->getVisibleSize();
    this->heroManager->setScene(this);
    this->heroManager->spawnHero(job, Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->heroManager->getHero()->setScale(2);

}

void RestRoomScene::chooseHero()
{
    auto visibleSize = Singleton<GameManager>::getIntsance()->getVisibleSize();

    knightButton = new Entity();
    elfButton = new Entity();

    knightButton->setTag(KNIGHT_TAG);
    elfButton->setTag(ELF_TAG);

    knightButton->setSpriteFrame(KNIGHT_M_IDLE, 0);
    elfButton->setSpriteFrame(ELF_M_IDLE, 0);

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
            CCLOG("knight touched %s", "yes");
            heroJob = HeroJob::Knight;
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
            CCLOG("elf touched %s", "yes");
            heroJob = HeroJob::Elf;
            this->goDungeonLayer->setVisible(true);
        }
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchElfListener, elfButton);

}

void RestRoomScene::goDungeon()
{
    auto visibleSize = Singleton<GameManager>::getIntsance()->getVisibleSize();
    goDungeonLayer = LayerColor::create(Color4B::GRAY);
    goDungeonLayer->setOpacity(100);
    goDungeonLayer->setContentSize(Size(160, 160));
    goDungeonLayer->setPosition(visibleSize / 2 - goDungeonLayer->getContentSize() / 2);
    goDungeonLayer->setVisible(false);
    this->addChild(goDungeonLayer);
    Vector<MenuItem*> menuItems = {
    MenuItemLabel::create(Label::createWithSystemFont("Play", "Arial", 40)  , [=](Ref* sender) {
        this->isGoDungeonLayerOpen = false;
        //pauseBtn->setEnabled(true);
        //GameManager::resume();
    }),
    MenuItemLabel::create(Label::createWithSystemFont("Back", "Arial", 40)  , [=](Ref* sender) {
        this->goDungeonLayer->setVisible(false);
    }),
    };

    auto menu = Menu::createWithArray(menuItems);
    goDungeonLayer->addChild(menu);
    menu->alignItemsVertically();
    menu->setPosition(goDungeonLayer->getContentSize() / 2);
}
