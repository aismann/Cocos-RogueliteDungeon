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
Entity::Entity():Sprite()
{
    this->animate = nullptr;
    this->animation = nullptr;
    this->speed = 0; 
}

Entity::~Entity()
{
}

void Entity::setSpriteFrame(std::string frameName, int number, bool haveBody)
{
    std::string spriteFrameName = frameName +"(" + std::to_string(number)+")";
    if (!this->initWithSpriteFrameName(spriteFrameName))
    {
        return;
    }
    this->getTexture()->setAliasTexParameters();
    if (haveBody)
    {
        PhysicsShapeCache::getInstance()->setBodyOnSprite(spriteFrameName, this);
    }
}

void Entity::setAnimation(REPEAT repeat, std::string animationName, int startFrame, int endFrame, float frameDelay)
{
    this->stopAllActions();
    this->frameName = animationName;
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

std::string Entity::getFrameName()
{
    return this->frameName;
}

cocos2d::Vec2 Entity::getEntityDirection()
{
    return this->direction;
}

void Entity::setEntityDirection(cocos2d::Vec2 direction)
{
    this->direction = direction;
    this->direction.normalize();
    this->getPhysicsBody()->setVelocity(this->speed * this->getEntityDirection());
}

float Entity::getEntitySpeed()
{
    return this->speed;
}

void Entity::setEntitySpeed(float speed)
{
    this->speed = speed;
}

void Entity::update(float dt)
{
    for (auto i = 0; i < this->animation->getFrames().size(); i++)
    {
        if(this->getSpriteFrame() == this->animation->getFrames().at(i)->getSpriteFrame())
        {
            //PhysicsShapeCache::getInstance()->setBodyOnSprite(this->frameName + "(" + std::to_string(i) + ")", this);

        }
        /*else if (this->isFlippedX() == true && this->getSpriteFrame() == this->animation->getFrames().at(i)->getSpriteFrame())
        {
            PhysicsShapeCache::getInstance()->setBodyOnSprite(this->frameName + "_flip(" + std::to_string(i) + ")", this);
        }*/
    }
}

