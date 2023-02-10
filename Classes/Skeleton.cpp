#include "Skeleton.h"
#include "HeroManager.h"
USING_NS_CC;

Skeleton::Skeleton():Enemy()
{
    StatModifier* baseHP = new StatModifier(10, StatModifierType::Flat, this);
    StatModifier* baseATK = new StatModifier(2, StatModifierType::Flat, 0, this);
    StatModifier* baseATSP = new StatModifier(0.65, StatModifierType::Flat, 0, this);
    StatModifier* baseMSP = new StatModifier(85, StatModifierType::Flat, 0, this);

    this->maxHealth.addModifier(baseHP);
    this->health = this->maxHealth.getValue();

    this->maxDamage.addModifier(baseATK);
    this->damage = this->maxDamage.getValue();

    this->maxAttackSpeed.addModifier(baseATSP);
    this->attackSpeed = this->maxAttackSpeed.getValue();

    this->maxMovementSpeed.addModifier(baseMSP);
    this->movementSpeed = this->maxMovementSpeed.getValue();

    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setSpriteFrame(SKELETON_IDLE, frameBegin, true);
    this->setAnimation(REPEAT::FOREVER, SKELETON_IDLE, frameBegin, frameEnd, frameDelay);
}

Skeleton::~Skeleton()
{
}

void Skeleton::takeDamage(float damage)
{
    this->health -= damage;
    if (this->health <= 0)
    {
        this->health = 10;
        Singleton<HeroManager>::getIntsance()->getHero()->setExp(10);
    }
    log("Enemy HP [%f]", this->health);
}

void Skeleton::entityIdle()
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, SKELETON_IDLE, frameBegin, frameEnd, frameDelay);
}

void Skeleton::entityRun()
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, SKELETON_RUN, frameBegin, frameEnd, frameDelay);
}

void Skeleton::entityAttack(std::function<void()> onFinish)
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    //this->setAnimation(REPEAT::FOREVER, SKELETON_IDLE, frameBegin, frameEnd, frameDelay);
    this->spriteFrameName = SKELETON_IDLE;
    this->animation = createAnimation(SKELETON_IDLE, frameBegin, frameEnd, frameDelay);
    this->animate = Animate::create(this->animation);
    this->runAction(Sequence::create(DelayTime::create(0.5f), CallFunc::create([=]() {
        onFinish();
        }), nullptr));
    this->setIsEntityTakeDamage(true);
}

void Skeleton::entityShoot(std::function<void()> onFinish)
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, SKELETON_IDLE, frameBegin, frameEnd, frameDelay);
}

void Skeleton::entityBehavior()
{
    Vec2 heroPos = Singleton<HeroManager>::getIntsance()->getHero()->getPosition();
    Vec2 aimDirection = heroPos - this->getPosition();
    aimDirection.normalize();

    setDirection(Vec2(aimDirection));

    if (aimDirection.x > 0)
    {
        this->setFlippedX(false);
    }
    else if (aimDirection.x = 0)
    {
        this->setFlippedX(true);
    }
    else
    {
        this->setFlippedX(true);
    }

    this->distance = this->getPosition().distance(heroPos);
    log("distance = %f", this->distance);
    if (distance > 20 && this->currentBehavior == Behavior::None)
    {
        //log("Run");
        this->nextBehavior = Behavior::Run;
        //log("Behavior = %d", this->nextBehavior);
    }
    else if (distance <=20 && this->currentBehavior == Behavior::None)
    {
        //log("Idle");
        this->nextBehavior = Behavior::Idle;
        //log("Behavior = %d", this->nextBehavior);
    }

    if (nextBehavior == Behavior::Attack && this->currentBehavior == Behavior::None)
    {
        auto attack = CallFunc::create([&]() {
            //this->setSpeed(0);
            this->isIdleActive = false;
            this->isRunActive = false;
            this->currentBehavior = Behavior::Attack;
            std::function<void()> onFinish = [=]() {
                this->currentBehavior = Behavior::None;
                this->isAttackActive = true;
            };
            this->entityAttack(onFinish);
            });
        auto sequence = Sequence::create(attack, DelayTime::create(0.5f), nullptr);
        auto repeatAttack = RepeatForever::create(sequence);
        this->runAction(repeatAttack);
    }

    if (nextBehavior == Behavior::Run && this->currentBehavior == Behavior::None)
    {
        log("Run");
        this->setSpeed(this->getMovementSpeed());
        this->isIdleActive = false;
        this->isAttackActive = false;
        if (!this->isRunActive)
        {
            this->entityRun();
            this->isRunActive = true;
        }
    }
    if (nextBehavior == Behavior::Idle && this->currentBehavior == Behavior::None)
    {
        this->setSpeed(0);
        this->isRunActive = false;
        this->isAttackActive = false;
        if (!this->isIdleActive)
        {
            this->entityIdle();
            this->isIdleActive = true;
        }
    }
}

void Skeleton::entityDie()
{
}

void Skeleton::setIsEntityTakeDamage(bool value)
{
    this->isTakeDamage = value;
}

bool Skeleton::getIsEntityTakeDamage()
{
    return this->isTakeDamage;
}

void Skeleton::setIsEntityRun(bool value)
{
    this->isRun = value;
}

bool Skeleton::getIsEntityRun()
{
    return this->isRun;
}

void Skeleton::attacking()
{

}

void Skeleton::setIsEntityAttack(bool value)
{
    if (value)
    {
        auto attack = CallFunc::create([&]() {
            this->attacking();
            });
        auto sequence = Sequence::create(attack,DelayTime::create(0.5f),nullptr);
        auto repeatAttack = RepeatForever::create(sequence);
        this->runAction(repeatAttack);
    }
}

void Skeleton::shooting()
{
}

void Skeleton::setIsEntityShooting(bool value)
{
    if (value)
    {
        auto shoot = CallFunc::create([&]() {
            this->shooting();
            });
        auto sequence = Sequence::create(shoot, DelayTime::create(0.5f), nullptr);
        auto repeatShoot = RepeatForever::create(sequence);
        this->runAction(repeatShoot);
    }
}

void Skeleton::update(float dt)
{
    if (isDie == false)
    {
        this->entityBehavior();
    }
}
