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

}

Entity::~Entity()
{
}

void Entity::setSpriteFrame(std::string _framename, int _number)
{
    std::string frameName = _framename + std::to_string(_number);
	this->initWithSpriteFrameName(frameName +".png");
    this->getTexture()->setAliasTexParameters();
    this->setScale(2);
    PhysicsShapeCache::getInstance()->setBodyOnSprite(frameName, this);
}

void Entity::setAnimation(REPEAT _repeat, std::string _animate, int _begin, int _end, float _delay)
{
    this->stopAllActions();
    this->bodyFrameName = _animate;
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

void Entity::setEntityVelocity(float speed, cocos2d::Vec2 direction)
{
    direction.normalize();
    this->getPhysicsBody()->setVelocityLimit(velocityLimit);
    this->getPhysicsBody()->setVelocity(speed*direction);
}

void Entity::update(float dt)
{
    for (auto i = 0; i < this->animation->getFrames().size(); i++)
    {
        if (this->getSpriteFrame() == this->animation->getFrames().at(i)->getSpriteFrame())
        {
            PhysicsShapeCache::getInstance()->setBodyOnSprite(this->bodyFrameName + std::to_string(i), this);
        }
    }
}

