#include "RestRoomScene.h"
#include "PhysicsShapeCache.h"
USING_NS_CC;

void RestRoomScene::initTileMap(cocos2d::Vec2 position)
{
    this->restroom = TMXTiledMap::create("tilemaps/dungeon.tmx");
    this->restroom->setPosition(Vec2(position.x*0.5,position.y*0.5));
    this->restroom->setAnchorPoint(Vec2(0.5,0.5));
    this->restroom->setScaleX((80*16)/ this->restroom->getContentSize().width);
    this->restroom->setScaleY((45 * 16) /this->restroom->getContentSize().height);
    this->addChild(this->restroom,0);
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
        this->restroom->addChild(wallNode);
    }
}

cocos2d::Vec2 RestRoomScene::tileCoordForPosition(cocos2d::Vec2 position)
{
    int x = position.x / restroom->getTileSize().width;
    int y = ((restroom->getMapSize().height * restroom->getTileSize().height) - position.y) / restroom->getTileSize().height;
    return cocos2d::Vec2(x,y);
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
        nodeA->setColor(Color3B::RED);
        nodeB->setColor(Color3B::RED);
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
        nodeA->setColor(Color3B::WHITE);
        nodeB->setColor(Color3B::WHITE);
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

    this->initTileMap((Vec2)visibleSize);

    this->hero->spawnHero(HeroJob::Lizard_M, Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->hero->getHero()->getPhysicsBody()->setRotationEnable(false);
    hero->getHero()->getPhysicsBody()->setGravityEnable(false);
    this->addChild(hero->getHero(),1);

    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    //this->getPhysicsWorld()->setGravity(Vec2(0,-98));
    scheduleUpdate();
    return true;
}

void RestRoomScene::update(float dt)
{
    hero->update(dt);
    Vec2 playerPos = this->hero->getHero()->getPosition();

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
