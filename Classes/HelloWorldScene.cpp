#include "HelloWorldScene.h"
#include "PhysicsShapeCache.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
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
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(KNIGHT_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(KNIGHT_BODY_PLIST);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ELF_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(ELF_BODY_PLIST);

    this->input->setKeyUp(EventKeyboard::KeyCode::KEY_W);
    this->input->setKeyDown(EventKeyboard::KeyCode::KEY_S);
    this->input->setKeyLeft(EventKeyboard::KeyCode::KEY_A);
    this->input->setKeyRight(EventKeyboard::KeyCode::KEY_D);

    this->hero->spawnHero(HeroJob::Elf_F, Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(hero->getHero());
    //this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt)
{
    hero->update(dt);
}
