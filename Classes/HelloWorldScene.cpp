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
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heros/Elf.plist");
    PhysicsShapeCache::getInstance()->addShapesWithFile("physicsbody/ElfBody.plist");
    entity = new Entity;
    entity->setSpriteFrame("elf_m_idle_anim_f", 0);
    entity->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    entity->setAnimation(REPEAT::FOREVER,"elf_f_idle_anim_f",0,3,0.15);
    this->addChild(entity);
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt)
{
    entity->update(dt);
}
