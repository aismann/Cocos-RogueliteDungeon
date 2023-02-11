#include "Orc.h"
#include "HeroManager.h"
#include "GameManager.h"
USING_NS_CC;

Orc::Orc():Enemy()
{
    StatModifier* baseHP = new StatModifier(7, StatModifierType::Flat, this);
    StatModifier* baseATK = new StatModifier(1, StatModifierType::Flat, 0, this);
    StatModifier* baseATSP = new StatModifier(0.75, StatModifierType::Flat, 0, this);
    StatModifier* baseMSP = new StatModifier(90, StatModifierType::Flat, 0, this);

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
    this->setSpriteFrame(ORC_IDLE, frameBegin, true);
    this->setAnimation(REPEAT::FOREVER, ORC_IDLE, frameBegin, frameEnd, frameDelay);
}

Orc::~Orc()
{
}

void Orc::setEnemyAlived()
{
    this->health = this->maxHealth.getValue();
    this->isDie = false;
}

void Orc::takeDamage(float damage)
{
    GameManager* gameManager = Singleton<GameManager>::getIntsance();
    HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
    this->health -= damage;
    if (this->health <= 0)
    {
        this->health = 0;
        gameManager->addDangerPoint(5);
        heroManager->getHero()->setExp(heroManager->getHero()->getExp()+12);
        heroManager->getHero()->setScorePoint(heroManager->getHero()->getScorePoint() + 2);
        if (this->isDie == false)
        {
            this->isDie = true;
        }
    }
    log("Enemy HP [%f]", this->health);
}

void Orc::entityIdle()
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, ORC_IDLE, frameBegin, frameEnd, frameDelay);

}

void Orc::entityRun()
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, ORC_RUN, frameBegin, frameEnd, frameDelay);

}

void Orc::entityAttack(std::function<void()> onFinish)
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->spriteFrameName = ORC_ATTACK;
    this->animation = createAnimation(ORC_ATTACK, frameBegin, frameEnd, frameDelay);
    this->animate = Animate::create(this->animation);
    this->runAction(RepeatForever::create(animate));
    this->attacking();
    this->runAction(Sequence::create(DelayTime::create(1/this->getAttackSpeed()), CallFunc::create([=]() {
        onFinish();
        }), nullptr));
}

void Orc::entitySkill(std::function<void()> onFinish)
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, ORC_IDLE, frameBegin, frameEnd, frameDelay);
}

void Orc::entityBehavior(float dt)
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
    if (distance > 50 && this->currentBehavior == Behavior::None)
    {
        this->nextBehavior = Behavior::Run;
    }
    else if (distance > 20 && distance <= 50 && this->currentBehavior == Behavior::None)
    {
        this->nextBehavior = Behavior::Attack;
    }
    else if (distance <= 20 &&this->currentBehavior == Behavior::None)
    {
        this->nextBehavior = Behavior::Idle;
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

void Orc::entityDie()
{
}

void Orc::setIsEntityTakeDamage(bool value)
{
    this->isTakeDamage = value;
}

bool Orc::getIsEntityTakeDamage()
{
    return this->isTakeDamage;
}

void Orc::setIsEntityRun(bool value)
{
    this->isRun = value;
}

bool Orc::getIsEntityRun()
{
    return this->isRun;
}

void Orc::attacking()
{
    Vec2 heroPos = Singleton<HeroManager>::getIntsance()->getHero()->getPosition();
    Vec2 aimDirection = heroPos - this->getPosition();
    aimDirection.normalize();
    this->magic = this->magicPool.getOnce();
    this->sound = AudioEngine::play2d("audios/magic.mp3", false);
    this->magic->getPhysicsBody()->setRotationEnable(false);
    this->magic->setDamage(this->getDamage());
    this->magic->setLifeTime(1.f);
    this->magic->setPosition(this->getPosition() + 15 * aimDirection);
    auto speed = this->getMovementSpeed() * 1.5f;
    magic->setSpeed(speed);
    this->magic->setDirection(aimDirection);
    float radian = aimDirection.getAngle(Vec2(0, 1));
    float angle = radian * 180 / M_PI;
    this->magic->setRotation(angle);

    Singleton<GameManager>::getIntsance()->getScene()->addChild(magic);
    magicList.push_back(magic);
}

void Orc::update(float dt)
{
    if (isDie == false)
    {
        this->entityBehavior(dt);
    }
    std::list<OrcMagic*>::iterator it;
    std::list<OrcMagic*> removeArray;
    for (it = magicList.begin(); it != magicList.end(); ++it)
    {
        magic = *it;
        float life = magic->lifeTimeCouting(dt);

        if (life <= 0)
        {
            Singleton<GameManager>::getIntsance()->getScene()->removeChild(magic);
            removeArray.push_back(magic);
            addToPool(magic);
        }
    }
    for (it = removeArray.begin(); it != removeArray.end(); ++it) {
        magicList.remove(*it);
    }
}

void Orc::addToPool(OrcMagic* magic)
{
    magic->getPhysicsBody()->setRotationEnable(true);
    this->magicPool.returnObject(magic);
}
