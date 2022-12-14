#include "Entity.h"
#include "PhysicsShapeCache.h"
USING_NS_CC;
cocos2d::Animation* Entity::createAnimation(std::string _animate, int _begin, int _end, float _delay)
{
    Vector<SpriteFrame*> animFrame;
    for (auto i = _begin; i <= _end; i++)
    {
        char buffer[20] = { 0 };
        sprintf(buffer, "%d.png", i);
        auto framename = _animate + buffer;
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename);
        animFrame.pushBack(frame);
    }
    auto _animation = Animation::createWithSpriteFrames(animFrame, _delay);
    return _animation;
}
Entity::Entity()
{
    this->animate = NULL;
    this->animation = NULL;
    this->speed = 0;
    
}

Entity::~Entity()
{
}

void Entity::setSpriteFrame(std::string _framename, int _number)
{
    std::string _frameName = _framename + std::to_string(_number);
	this->initWithSpriteFrameName(_frameName +".png");
    this->getTexture()->setAliasTexParameters();
    this->setScale(2);
    PhysicsShapeCache::getInstance()->setBodyOnSprite(_frameName, this);
}

void Entity::setAnimation(REPEAT _repeat, std::string _animate, int _begin, int _end, float _delay)
{
    this->stopAllActions();
    this->frameName = _animate;
    this->animation = createAnimation(_animate, _begin, _end, _delay);
    animate = Animate::create(this->animation);
    switch (_repeat)
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

void Entity::setSpeedAndDirection(float speed, cocos2d::Vec2 direction)
{
    this->speed = speed;
    this->direction = direction;
    this->direction.normalize();
}

std::string Entity::getFrameName()
{
    return this->frameName;
}

cocos2d::Vec2 Entity::getDirection()
{
    return this->direction;
}

void Entity::update(float dt)
{
    for (auto i = 0; i < this->animation->getFrames().size(); i++)
    {
        if (this->getSpriteFrame() == this->animation->getFrames().at(i)->getSpriteFrame())
        {
            PhysicsShapeCache::getInstance()->setBodyOnSprite(this->frameName + std::to_string(i), this);
        }
    }
    float smoothspeed = this->speed;
    smoothspeed *= Director::getInstance()->getAnimationInterval() / dt;
    this->getPhysicsBody()->setVelocity(smoothspeed * this->getDirection());
}

