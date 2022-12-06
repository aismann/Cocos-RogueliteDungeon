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
}

Entity::~Entity()
{
}

void Entity::setSpriteFrame(std::string _framename, int _number)
{
	this->initWithSpriteFrameName(_framename + std::to_string(_number)+".png");
    this->getTexture()->setAliasTexParameters();
    this->setScale(2);
    PhysicsShapeCache::getInstance()->setBodyOnSprite("elf_f_idle_anim_f0", this);
}

void Entity::setAnimation(REPEAT _repeat, std::string _animate, int _begin, int _end, float _delay)
{
    this->stopAllActions();
    /*----------------------------------------*/

    /*----------------------------------------------*/
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
    //log("[%d]",this->getSpriteFrame());
    for (auto i = 0; i < this->animation->getFrames().size(); i++)
    {
        if (this->getSpriteFrame() == this->animation->getFrames().at(i)->getSpriteFrame())
        {
            PhysicsShapeCache::getInstance()->setBodyOnSprite("elf_f_idle_anim_f" + std::to_string(i), this);
        }
    }
}