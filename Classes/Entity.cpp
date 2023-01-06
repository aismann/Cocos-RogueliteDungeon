#include "Entity.h"
#include "PhysicsShapeCache.h"
USING_NS_CC;

cocos2d::Animation* Entity::createAnimation(std::string animationName, int startFrame, int endFrame, float frameDelay)
{
    Vector<SpriteFrame*> animationFrame;
    for (auto i = startFrame; i <= endFrame; i++)
    {
        char buffer[20] = { 0 };
        sprintf(buffer, "(%d)", i);
        auto frameName = animationName + buffer;
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
        animationFrame.pushBack(frame);
    }
    auto animation = Animation::createWithSpriteFrames(animationFrame, frameDelay);
    return animation;
}

Entity::Entity()
{
    this->animate = nullptr;
    this->animation = nullptr;
    this->speed = 0;
}

Entity::~Entity()
{
}

Entity* Entity::create()
{
    Entity* entity = new Entity();
    if (entity && entity->init())
    {
        entity->autorelease();
        return entity;
    }
    CC_SAFE_DELETE(entity);
    return nullptr;
}

bool Entity::init()
{
    this->initWithSpriteFrameName(ELF_M_IDLE + "(0)");
    this->getTexture()->setAliasTexParameters();
    return true;
}

void Entity::setSpriteFrame(std::string frameName, int number, bool haveBody)
{
    this->unscheduleUpdate();
    std::string spriteFrameName = frameName + "(" + std::to_string(number) + ")";
    if (!this->initWithSpriteFrameName(spriteFrameName))
    {
        return;
    }
    if (haveBody)
    {
        PhysicsShapeCache::getInstance()->setBodyOnSprite(spriteFrameName, this);
    }
}

void Entity::setAnimation(REPEAT repeat, std::string animationName, int startFrame, int endFrame, float frameDelay)
{
    this->stopAllActions();
    this->spriteFrameName = animationName;
    this->animation = createAnimation(animationName, startFrame, endFrame, frameDelay);
    animate = Animate::create(this->animation);
    switch (repeat)
    {
    case REPEAT::FOREVER:
        this->runAction(RepeatForever::create(animate));
        break;
    case REPEAT::ONCE:
        this->runAction(Repeat::create(animate, 1));
        break;
    default:
        break;
    }
}

cocos2d::Vec2 Entity::getDirection()
{
    return this->direction;
}

void Entity::setDirection(cocos2d::Vec2 direction)
{
    this->direction = direction;
    this->direction.normalize();
    this->getPhysicsBody()->setVelocity(this->speed * this->direction);
}

float Entity::getSpeed()
{
    return this->speed;
}

void Entity::setSpeed(float speed)
{
    this->speed = speed;
}

void Entity::update(float dt)
{
}

void Entity::takeDamage(float damage)
{
}

