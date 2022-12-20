#include "HelloWorldScene.h"
#include "PhysicsShapeCache.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::onContactBegin(cocos2d::PhysicsContact& _contact)
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

void HelloWorld::onContactSeparate(cocos2d::PhysicsContact& _contact)
{
    auto nodeA = _contact.getShapeA()->getBody()->getNode();
    auto nodeB = _contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        nodeA->setColor(Color3B::WHITE);
        nodeB->setColor(Color3B::WHITE);
    }
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(HelloWorld::onContactSeparate, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    /*SpriteFrameCache::getInstance()->addSpriteFramesWithFile(KNIGHT_M_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(KNIGHT_M_BODY_PLIST);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(KNIGHT_F_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(KNIGHT_F_BODY_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ELF_M_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(ELF_M_BODY_PLIST);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ELF_F_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(ELF_F_BODY_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(LIZARD_M_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(LIZARD_M_BODY_PLIST);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(LIZARD_F_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(LIZARD_F_BODY_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(WIZARD_M_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(WIZARD_M_BODY_PLIST);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(WIZARD_F_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(WIZARD_F_BODY_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(WEAPON_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(WEAPON_BODY_PLIST);

    this->input->setKeyUp(EventKeyboard::KeyCode::KEY_W);
    this->input->setKeyDown(EventKeyboard::KeyCode::KEY_S);
    this->input->setKeyLeft(EventKeyboard::KeyCode::KEY_A);
    this->input->setKeyRight(EventKeyboard::KeyCode::KEY_D);*/

    this->hero->spawnHero(HeroJob::Lizard_M, Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(hero->getHero());

    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt)
{
    hero->update(dt);
}
