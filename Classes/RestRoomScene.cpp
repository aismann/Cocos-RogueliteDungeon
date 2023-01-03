#include "RestRoomScene.h"
#include "PhysicsShapeCache.h"
#include "Sword.h"
USING_NS_CC;

void RestRoomScene::initTileMap(cocos2d::Vec2 position)
{
    this->restroom = TMXTiledMap::create("tilemaps/dungeon.tmx");
    this->restroom->setPosition(Vec2(position.x*0.5,position.y*0.5));
    this->restroom->setAnchorPoint(Vec2(0.5,0.5));
    this->restroom->setScaleX((80*16)/ this->restroom->getContentSize().width);
    this->restroom->setScaleY((45 * 16) /this->restroom->getContentSize().height);
    this->addChild(this->restroom,-2);
    this->restroom->getLayer("bottomwall")->setGlobalZOrder(2);

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
        wallBody->setCategoryBitmask(40);
        wallBody->setContactTestBitmask(1);
        auto wallNode = Node::create();
        wallNode->setPosition(x, y);
        wallNode->setPhysicsBody(wallBody);
        wallNode->setContentSize(objectSize);
        this->restroom->addChild(wallNode,2);
    }
}

cocos2d::Vec2 RestRoomScene::tileCoordForPosition(cocos2d::Vec2 position)
{
    int x = position.x / restroom->getTileSize().width;
    int y = ((restroom->getMapSize().height * restroom->getTileSize().height) - position.y) / restroom->getTileSize().height;
    return cocos2d::Vec2(x,y);
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
    auto visibleSize = this->heroManager->getVisibleSize();
    targetPos.x = clampf(targetPos.x, (visibleSize.x - (BOUNDING_BOX.width - visibleSize.x)) / 2, (visibleSize.x + (BOUNDING_BOX.width - visibleSize.x)) / 2);
    targetPos.y = clampf(targetPos.y, (visibleSize.y - (BOUNDING_BOX.height - visibleSize.y)) / 2, (visibleSize.y + (BOUNDING_BOX.height - visibleSize.y)) / 2);
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
    if ((_contact.getShapeA()->getCategoryBitmask() & _contact.getShapeB()->getCollisionBitmask()) <= 0 ||
        (_contact.getShapeB()->getCategoryBitmask() & _contact.getShapeA()->getCollisionBitmask()) <= 0)
    {
        return false;
    }

    auto nodeA = _contact.getShapeA()->getBody()->getNode();
    auto nodeB = _contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        //nodeA->setColor(Color3B::RED);
        //nodeB->setColor(Color3B::RED);
        //Entity* entityA = GameManager::findEntity((Sprite*)nodeA);
        //Entity* entityB = GameManager::findEntity((Sprite*)nodeB);

        //if (entityA && entityB)
        //{
        //    float damageA = entityA->getAtk();
        //    float damageB = entityB->getAtk();
        //    entityA->takeDamage(damageB);
        //    entityB->takeDamage(damageA);
        //}
    }
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
    this->heroManager->setScene(this);
    this->heroManager->spawnHero(HeroJob::Lizard, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    Weapon* sword = new Sword();
    sword->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5));
    //this->addChild(sword,1);
    Weapon* sword2 = new Sword();
    sword2->setColor(Color3B::RED);
    //sword2->setTag(2);
    sword2->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.6));
    Weapon* sword3 = new Sword();
    sword3->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.6));
    sword3->setColor(Color3B::BLUE);
    Singleton<ItemManager>::getIntsance()->setScene(this);
    Singleton<ItemManager>::getIntsance()->setVisibleSize((Vec2)visibleSize);
    Singleton<ItemManager>::getIntsance()->addItem(sword);
    Singleton<ItemManager>::getIntsance()->addItem(sword2);
    Singleton<ItemManager>::getIntsance()->addItem(sword3);
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    //this->getPhysicsWorld()->setGravity(Vec2(0,-98));
    scheduleUpdate();
    return true;
}

void RestRoomScene::update(float dt)
{
    this->followHero();
    heroManager->update(dt);
    //Vec2 playerPos = this->hero->getHero()->getPosition();

    //auto tileID = this->bottomWall->getTileGIDAt(tileCoordForPosition(playerPos));
    //if (tileID)
    //{
    //    log("[%d]",tileID);
    //    //auto properties = this->collision->getProperties().at("Collision").asBool();
    //    //auto pos = this->collision->getTileAt(tileCoordForPosition(playerPos));
    //    if (properties == true)
    //    {
    //        //log("[%f][%f]", pos->getPositionX(), pos->getPositionY());
    //        //pos->unscheduleUpdate();
    //        //auto body = PhysicsBody::createBox(pos->getContentSize(),PhysicsMaterial(1,0,0));
    //        //body->setDynamic(false);
    //        //body->setContactTestBitmask(0xffff);
    //        //body->setCategoryBitmask(40);
    //        //body->setContactTestBitmask(1);
    //        //pos->setPhysicsBody(body);
    //    }
    //}
}
