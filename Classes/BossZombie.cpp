#include "BossZombie.h"
#include "HeroManager.h"
#include "GameManager.h"
#include "SkeletonSlash.h"
#include "ClosingScene.h"
USING_NS_CC;

BossZombie::BossZombie():Enemy()
{

    StatModifier* baseHP = new StatModifier(50, StatModifierType::Flat, this);
    StatModifier* baseMN = new StatModifier(10, StatModifierType::Flat, this);
    StatModifier* baseATK = new StatModifier(3, StatModifierType::Flat, 0, this);
    StatModifier* baseATSP = new StatModifier(0.65, StatModifierType::Flat, 0, this);
    StatModifier* baseMSP = new StatModifier(80, StatModifierType::Flat, 0, this);

    this->maxHealth.addModifier(baseHP);
    this->health = this->maxHealth.getValue();

    this->maxMana.addModifier(baseMN);
    this->mana = this->maxMana.getValue();

    this->maxDamage.addModifier(baseATK);
    this->damage = this->maxDamage.getValue();

    this->maxAttackSpeed.addModifier(baseATSP);
    this->attackSpeed = this->maxAttackSpeed.getValue();

    this->maxMovementSpeed.addModifier(baseMSP);
    this->movementSpeed = this->maxMovementSpeed.getValue();

    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setSpriteFrame(ZOMBIEBOSS_IDLE, frameBegin, true);
    this->setAnimation(REPEAT::FOREVER, ZOMBIEBOSS_IDLE, frameBegin, frameEnd, frameDelay);

    hpBarBG = Sprite::create("ui/hpBarBG.png");
    hpBar = Sprite::create("ui/hpBar.png");

    hpBarBG->setContentSize(Size(30, 3));
    hpBarBG->setAnchorPoint(Vec2(0, 0.5));
    hpBar->setContentSize(Size(30, 3));
    hpBar->setAnchorPoint(Vec2(0, 0.5));

    hpBarBG->setPosition(this->getContentSize().width/2 - hpBarBG->getContentSize().width/2, -4);
    hpBar->setPosition(this->getContentSize().width / 2 - hpBar->getContentSize().width / 2, -4);

    this->addChild(hpBarBG);
    this->addChild(hpBar);
}

BossZombie::~BossZombie()
{
}

void BossZombie::setEnemyAlived()
{
    this->health = this->maxHealth.getValue();
    this->isDie = false;
}

void BossZombie::takeDamage(float damage)
{
    GameManager* gameManager = Singleton<GameManager>::getIntsance();
    HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
    this->health -= damage;
    if (this->health <= 0)
    {
        this->health = 0;
        heroManager->getHero()->setExp(heroManager->getHero()->getExp()+25);
        heroManager->getHero()->setScorePoint(heroManager->getHero()->getScorePoint() + 10);
        if (this->isDie == false)
        {
            this->isDie = true;
        }
    }
    log("Enemy HP [%f]", this->health);

    if (this->isDie == true)
    {
        this->stopAllActions();
        Sprite* effectNode = Sprite::create();
        effectNode->setSpriteFrame(ZOMBIEBOSS_IDLE + "(0)");
        effectNode->setAnchorPoint(Vec2(0.5, 0));
        gameManager->getScene()->addChild(effectNode);
        effectNode->setPosition(this->getPosition());
        auto sequence = Sequence::create(DelayTime::create(1.5), CallFunc::create([&]() {auto clossingscene = ClosingScene::create(); Director::getInstance()->replaceScene(clossingscene); }), nullptr);
        effectNode->runAction(sequence);
    }
}

void BossZombie::entityIdle()
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, ZOMBIEBOSS_IDLE, frameBegin, frameEnd, frameDelay);

}

void BossZombie::entityRun()
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setAnimation(REPEAT::FOREVER, ZOMBIEBOSS_RUN, frameBegin, frameEnd, frameDelay);

}

void BossZombie::entityAttack(std::function<void()> onFinish)
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->spriteFrameName = ZOMBIEBOSS_ATTACK;
    this->animation = createAnimation(ZOMBIEBOSS_ATTACK, frameBegin, frameEnd, frameDelay);
    this->animate = Animate::create(this->animation);
    this->runAction(RepeatForever::create(animate));
    this->attacking();
    this->addManaPoint(2);
    this->runAction(Sequence::create(DelayTime::create(1/this->getAttackSpeed()), CallFunc::create([=]() {
        onFinish();
        }), nullptr));
}

void BossZombie::entitySkill(std::function<void()> onFinish)
{
    this->stopAllActions();
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->spriteFrameName = ZOMBIEBOSS_ATTACK;
    this->animation = createAnimation(ZOMBIEBOSS_ATTACK, frameBegin, frameEnd, frameDelay);
    this->animate = Animate::create(this->animation);
    this->runAction(RepeatForever::create(animate));
    this->bossSkill();
    this->runAction(Sequence::create(DelayTime::create(1 / this->getAttackSpeed()), CallFunc::create([=]() {
        onFinish();
        }), nullptr));
}

void BossZombie::entityBehavior(float dt)
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
    else if (distance <=30 && this->currentBehavior == Behavior::None)
    {
        if (this->manaPoint >= this->getMana())
        {
            this->nextBehavior = Behavior::Skill;
            this->manaPoint = 0;
        }
        else
        {
            this->nextBehavior = Behavior::Attack;
        }
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

    if (nextBehavior == Behavior::Skill && this->currentBehavior == Behavior::None)
    {
        auto skill = CallFunc::create([&]() {
            this->setSpeed(0);
        this->isIdleActive = false;
        this->isRunActive = false;
        this->currentBehavior = Behavior::Skill;
        std::function<void()> onFinish = [=]() {
            this->currentBehavior = Behavior::None;
            this->isSkillActive = true;
        };
        this->entitySkill(onFinish);
            });
        auto sequence = Sequence::create(skill, nullptr);
        auto repeatSkill = RepeatForever::create(sequence);
        this->runAction(repeatSkill);
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

void BossZombie::entityDie()
{
}

void BossZombie::setIsEntityTakeDamage(bool value)
{
    this->isTakeDamage = value;
}

bool BossZombie::getIsEntityTakeDamage()
{
    return this->isTakeDamage;
}

void BossZombie::setIsEntityRun(bool value)
{
    this->isRun = value;
}

bool BossZombie::getIsEntityRun()
{
    return this->isRun;
}

void BossZombie::attacking()
{
    Vec2 heroPos = Singleton<HeroManager>::getIntsance()->getHero()->getPosition();
    Vec2 aimDirection = heroPos - this->getPosition();
    aimDirection.normalize();
    this->punch = this->punchPool.getOnce();
    this->sound = AudioEngine::play2d("audios/punch.mp3", false);
    this->punch->getPhysicsBody()->setRotationEnable(false);
    this->punch->setDamage(this->getDamage());
    this->punch->setLifeTime(0.5f);
    this->punch->setPosition(this->getPosition() + 20 * aimDirection);
    auto speed = this->getMovementSpeed();
    punch->setSpeed(speed);
    this->punch->setDirection(aimDirection);
    float radian = aimDirection.getAngle(Vec2(0, 1));
    float angle = radian * 180 / M_PI;
    this->punch->setRotation(angle);

    Singleton<GameManager>::getIntsance()->getScene()->addChild(punch);
    punchList.push_back(punch);
}

void BossZombie::bossSkill()
{
    Vec2 heroPos = Singleton<HeroManager>::getIntsance()->getHero()->getPosition();
    Vec2 aimDirection = heroPos - this->getPosition();
    aimDirection.normalize();
    this->ground = this->groundPool.getOnce();
    this->sound = AudioEngine::play2d("audios/ground.mp3", false);
    this->ground->getPhysicsBody()->setRotationEnable(false);
    this->ground->setDamage(this->getDamage()*2);
    this->ground->setLifeTime(0.5f);
    this->ground->setPosition(this->getPosition() + 0 * aimDirection);
    auto speed = this->getMovementSpeed();
    ground->setSpeed(speed);
    this->ground->setDirection(aimDirection);

    float radian = aimDirection.getAngle(Vec2(0, 1));
    float angle = radian * 180 / M_PI;
    this->ground->setRotation(angle);
    Singleton<GameManager>::getIntsance()->getScene()->addChild(ground);
    groundList.push_back(ground);
}

void BossZombie::update(float dt)
{
    if (isDie == false)
    {
        this->entityBehavior(dt);
    }
    std::list<BossZombiePunch*>::iterator it;
    std::list<BossZombiePunch*> removeArray;
    for (it = punchList.begin(); it != punchList.end(); ++it)
    {
        punch = *it;
        float life = punch->lifeTimeCouting(dt);

        auto skeletonPos = this->getPosition();
        punch->setPosition(Vec2(skeletonPos.x, skeletonPos.y + this->getContentSize().height / 4));

        if (life <= 0)
        {
            Singleton<GameManager>::getIntsance()->getScene()->removeChild(punch);
            removeArray.push_back(punch);
            addToPool(punch);
        }
    }
    for (it = removeArray.begin(); it != removeArray.end(); ++it) {
        punchList.remove(*it);
    }

    std::list<BossZombieGround*>::iterator _it;
    std::list<BossZombieGround*> _removeArray;
    for (_it = groundList.begin(); _it != groundList.end(); ++_it)
    {
        ground = *_it;
        float life = ground->lifeTimeCouting(dt);

        auto skeletonPos = this->getPosition();
        ground->setPosition(Vec2(skeletonPos.x, skeletonPos.y + this->getContentSize().height / 4));

        if (life <= 0)
        {
            Singleton<GameManager>::getIntsance()->getScene()->removeChild(ground);
            _removeArray.push_back(ground);
            addToPool(ground);
        }
    }
    for (_it = _removeArray.begin(); _it != _removeArray.end(); ++_it) {
        groundList.remove(*_it);
    }

    this->updateHPBar(dt);
}

void BossZombie::addToPool(BossZombiePunch* punch)
{
    punch->getPhysicsBody()->setRotationEnable(true);
    this->punchPool.returnObject(punch);
}

void BossZombie::addToPool(BossZombieGround* ground)
{
    ground->getPhysicsBody()->setRotationEnable(true);
    this->groundPool.returnObject(ground);
}

float BossZombie::getManaPoint()
{
    return this->manaPoint;
}

void BossZombie::addManaPoint(float value)
{
    if (this->manaPoint >= this->getMana())
    {
        this->manaPoint = this->getMana();
    }
    else
    {
        this->manaPoint += value;
    }
}

void BossZombie::updateHPBar(float dt)
{

    Size hpBarSize = hpBar->getContentSize();

    float speed = 1.5f;
    float newHP = this->getHealth() / this->getMaxHealth()
        * hpBarBG->getContentSize().width;
    hpBarSize.width = MathUtil::lerp(hpBarSize.width, newHP, dt * speed);
    hpBar->setContentSize(hpBarSize);
}
