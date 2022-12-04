#include "HelloWorldScene.h"
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
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("elf.plist");
    auto bouding = Node::create();
    bouding->setContentSize(visibleSize/2);
    bouding->setPosition(visibleSize/2);
    bouding->setAnchorPoint(Vec2(0.5,0.5));
    auto boubody = PhysicsBody::createEdgeBox(visibleSize/2);
    bouding->setPhysicsBody(boubody);
    this->addChild(bouding);
    entity = new Entity;
    entity->setSpriteFrame("elf_m_idle", 0);
    entity->setAnimation(REPEAT::FOREVER,"elf_m_idle",0,3,0.25);
    entity->setPosition(visibleSize/2);
    entity->getTexture()->setAliasTexParameters();
    entity->setAnimation(REPEAT::FOREVER, "elf_f_idle", 0, 3, 0.25);
    this->addChild(entity);
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    return true;
}

void HelloWorld::update(float dt)
{
    entity->update(dt);
}
