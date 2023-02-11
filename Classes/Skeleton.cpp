#include "Skeleton.h"
#include "HeroManager.h"
#include "GameManager.h"
#include "SkeletonSlash.h"
USING_NS_CC;

Skeleton::Skeleton():Enemy()
{
    StatModifier* baseHP = new StatModifier(10, StatModifierType::Flat, this);
    StatModifier* baseATK = new StatModifier(2, StatModifierType::Flat, 0, this);
    StatModifier* baseATSP = new StatModifier(0.55, StatModifierType::Flat, 0, this);
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

void Skeleton::setEnemyAlived()
{
    this->health = this->maxHealth.getValue();
    this->isDie = false;
}

void Skeleton::takeDamage(float damage)
{
    GameManager* gameManager = Singleton<GameManager>::getIntsance();
    HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
    this->health -= damage;
    if (this->health <= 0)
    {
        this->health = 0;
        gameManager->addDangerPoint(2);
        heroManager->getHero()->setExp(heroManager->getHero()->getExp()+9);
        heroManager->getHero()->setScorePoint(heroManager->getHero()->getScorePoint() + 1);
        if (this->isDie == false)
        {
            this->isDie = true;
        }

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
    this->spriteFrameName = SKELETON_ATTACK;
    this->animation = createAnimation(SKELETON_ATTACK, frameBegin, frameEnd, frameDelay);
    this->animate = Animate::create(this->animation);
    this->runAction(RepeatForever::create(animate));
    this->attacking();
    this->runAction(Sequence::create(DelayTime::create(1/this->getAttackSpeed()), CallFunc::create([=]() {
        onFinish();
        }), nullptr));
}

void Skeleton::entitySkill(std::function<void()> onFinish)
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, SKELETON_IDLE, frameBegin, frameEnd, frameDelay);
}

void Skeleton::entityBehavior(float dt)
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
    if (distance > 30 && this->currentBehavior == Behavior::None)
    {
        this->nextBehavior = Behavior::Run;
    }
    else if (distance >= 20  && distance <=30 && this->currentBehavior == Behavior::None)
    {
        this->nextBehavior = Behavior::Attack;
    }

    if (nextBehavior == Behavior::Attack && this->currentBehavior == Behavior::None)
    {
        auto attack = CallFunc::create([&]() {
            this->setSpeed(0);
        this->isIdleActive = false;
        this->isRunActive = false;
        this->currentBehavior = Behavior::Attack;
        std::function<void()> onFinish = [=]() {
            this->currentBehavior = Behavior::None;
            this->isAttackActive = true;
        };
        this->entityAttack(onFinish);
            });
        auto sequence = Sequence::create(attack, nullptr);
        auto repeatAttack = RepeatForever::create(sequence);
        this->runAction(repeatAttack);
    }

    if (nextBehavior == Behavior::Run && this->currentBehavior == Behavior::None)
    {
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
    Vec2 heroPos = Singleton<HeroManager>::getIntsance()->getHero()->getPosition();
    Vec2 aimDirection = heroPos - this->getPosition();
    aimDirection.normalize();
    this->slash = this->slashPool.getOnce();
    this->sound = AudioEngine::play2d("audios/punch.mp3", false);
    this->slash->setScale(0.75f);
    this->slash->getPhysicsBody()->setRotationEnable(false);
    this->slash->setDamage(this->getDamage());
    this->slash->setLifeTime(0.5f);
    this->slash->setPosition(this->getPosition() + 0 * aimDirection);
    auto speed = this->getMovementSpeed();
    slash->setSpeed(speed);
    this->slash->setDirection(aimDirection);

    float radian = aimDirection.getAngle(Vec2(0, 1));
    float angle = radian * 180 / M_PI;
    this->slash->setRotation(angle);
    log("=== direction : %f %f ===", this->slash->getDirection().x, this->slash->getDirection().y);
    Singleton<GameManager>::getIntsance()->getScene()->addChild(slash);
    slashList.push_back(slash);
}

void Skeleton::update(float dt)
{
    if (isDie == false)
    {
        this->entityBehavior(dt);
    }
    std::list<SkeletonSlash*>::iterator it;
    std::list<SkeletonSlash*> removeArray;
    for (it = slashList.begin(); it != slashList.end(); ++it)
    {
        slash = *it;
        float life = slash->lifeTimeCouting(dt);

        auto skeletonPos = this->getPosition();
        slash->setPosition(Vec2(skeletonPos.x, skeletonPos.y + this->getContentSize().height / 4));

        if (life <= 0)
        {
            Singleton<GameManager>::getIntsance()->getScene()->removeChild(slash);
            removeArray.push_back(slash);
            addToPool(slash);
        }
    }
    for (it = removeArray.begin(); it != removeArray.end(); ++it) {
        slashList.remove(*it);
    }
}

void Skeleton::addToPool(SkeletonSlash* slash)
{
    slash->getPhysicsBody()->setRotationEnable(true);
    this->slashPool.returnObject(slash);
}
