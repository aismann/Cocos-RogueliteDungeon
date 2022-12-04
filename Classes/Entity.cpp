#include "Entity.h"
USING_NS_CC;
cocos2d::Animation* Entity::createAnimation(std::string _animate, int _begin, int _end, float _delay)
{
    Vector<SpriteFrame*> animFrame;
    for (auto i = _begin; i <= _end; i++)
    {
        char buffer[20] = { 0 };
        sprintf(buffer, "(%d).png", i);
        auto framename = _animate + buffer;
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(framename);
        animFrame.pushBack(frame);
    }
    auto _animation = Animation::createWithSpriteFrames(animFrame, _delay);
    return _animation;
}
Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::setSpriteFrame(std::string _framename, int _number)
{
	this->initWithSpriteFrameName(_framename + "(" + std::to_string(_number)+").png");
    this->setAnchorPoint(Vec2(0.5,0));
}

void Entity::setAnimation(REPEAT _repeat, std::string _animate, int _begin, int _end, float _delay)
{
    this->stopAllActions();
    this->removeComponent(this->body);
    this->body = PhysicsBody::createBox(this->getContentSize());
    this->setPhysicsBody(this->body);
    this->getPhysicsBody()->setRotationEnable(false);
    this->getPhysicsBody()->setDynamic(false);
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

void Entity::update(float dt)
{

}