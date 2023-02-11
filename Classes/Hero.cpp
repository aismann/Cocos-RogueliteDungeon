#include "Hero.h"
#include "HeroIdleState.h"
USING_NS_CC;

Hero::Hero():Entity()
{
    this->setTag(HERO_TAG);
    this->xCoordinate = 0;
    this->yCoordinate = 0;
    this->wallContact = false;

    this->heroJob = HeroJob::None;

    this->activeState = new HeroIdleState();
    this->activeState->addHero(this);
    this->activeState->onStart();

    this->initListener();
    this->initHero();
}

Hero::~Hero()
{
    CC_SAFE_DELETE(this->activeState);
}
HeroJob Hero::getHeroJob()
{
    return this->heroJob;
}

float Hero::getXCoordinate()
{
    return this->xCoordinate;
}

void Hero::setXCoordinate(float xCoord)
{
    this->xCoordinate += xCoord;
}

float Hero::getYCoordinate()
{
    return this->yCoordinate;
}

void Hero::setYCoordinate(float yCoord)
{
    this->yCoordinate += yCoord;
}

int Hero::getExp()
{
    return this->exp;
}

void Hero::setExp(int exp)
{
    this->exp = exp;
    if (this->exp >= (int)this->expList[this->getLevel()-1])
    {
        this->setLevel(this->getLevel() + 1);
    }
}

int Hero::getExpList(int level)
{
    return this->expList[level-1];
}

int Hero::getLevel()
{
    return this->level;
}

void Hero::setLevel(int level)
{
    this->level = level;
    this->upgradepoint += 1;
}

int Hero::getUpgradePoint()
{
    return this->upgradepoint;
}

void Hero::setUpgradePoint(int upgradepoint)
{
    this->upgradepoint = upgradepoint;
}

int Hero::getScorePoint()
{
    return this->scorepoint;
}

void Hero::setScorePoint(int scorepoint)
{
    this->scorepoint = scorepoint;
}

void Hero::setMaxHealth(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxHealth.addModifier(baseValue);
    this->health = this->maxHealth.getValue();
}

float Hero::getHealth()
{
    return this->health;
}

void Hero::setMaxShield(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxShield.addModifier(baseValue);
    this->shield = this->maxShield.getValue();
}

float Hero::getShield()
{
    return this->shield;
}

void Hero::setMaxDamage(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxDamage.addModifier(baseValue);
    this->damage = this->maxDamage.getValue();
}

float Hero::getDamage()
{
    return this->damage;
}

void Hero::setMaxAttackSpeed(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxAttackSpeed.addModifier(baseValue);
    this->attackSpeed = this->maxAttackSpeed.getValue();
}

float Hero::getAttackSpeed()
{
    return this->attackSpeed;
}

void Hero::setMaxMovementSpeed(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxMovementSpeed.addModifier(baseValue);
    this->movementSpeed = this->maxMovementSpeed.getValue();
}

float Hero::getMovementSpeed()
{
    return this->movementSpeed;
}

float Hero::getMaxHealth()
{
    return this->maxHealth.getValue();
}

float Hero::getMaxShield()
{
    return this->maxShield.getValue();
}

float Hero::getMaxDamage()
{
    return this->maxDamage.getValue();
}

float Hero::getMaxAttackSpeed()
{
    return this->maxAttackSpeed.getValue();
}

float Hero::getMaxMovementSpeed()
{
    return this->maxMovementSpeed.getValue();
}


void Hero::rotateWeaponByCursor(cocos2d::Vec2& location)
{
    location = Singleton<GameManager>::getIntsance()->getScene()->getDefaultCamera()->convertToWorldSpaceAR(location - Singleton<GameManager>::getIntsance()->getVisibleSize() / 2);
    Vec2 aimDirection = location - this->getPosition();
    aimDirection.normalize();
    float radian = aimDirection.getAngle(Vec2(0, 1));
    float degree = radian * 180 / M_PI;
    weaponNode->setRotation(degree);
}

void Hero::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    HeroBaseState* newState = this->activeState->onKeyPressed(keycode, event);
    if (newState)
    {
        changeState(newState);
    }
}

void Hero::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    HeroBaseState* newState = this->activeState->onKeyReleased(keycode, event);
    if (newState)
    {
        changeState(newState);
    }
}

void Hero::onMouseDown(cocos2d::Event* event)
{
    HeroBaseState* newState = this->activeState->onMouseDown(event);
    if (newState)
    {
        changeState(newState);
    }
}

void Hero::onMouseUp(cocos2d::Event* event)
{
    HeroBaseState* newState = this->activeState->onMouseUp(event);
    if (newState)
    {
        changeState(newState);
    }
}

void Hero::onMouseMove(cocos2d::Event* event)
{
    HeroBaseState* newState = this->activeState->onMouseMove(event);
    if (newState)
    {
        changeState(newState);
    }
}

Weapon* Hero::getWeapon()
{
    return this->weapon;
}

cocos2d::Sprite* Hero::getWeaponNode()
{
    return this->weaponNode;
}

void Hero::update(float dt)
{
    HeroBaseState* newState = this->activeState->update(dt);
    if (newState)
    {
        changeState(newState);
    }
}

void Hero::takeDamage(float damage)
{
    if (this->shield > 0 && damage > this->shield)
    {
        this->health -= (damage - this->shield);
        this->shield = 0;
    }
    else if (this->shield > 0 && damage < this->shield)
    {
        this->shield -= damage;
    }
    else if (damage == this->shield)
    {
        this->shield = 0;
    }
    else if (this->shield == 0)
    {
        this->health -= damage;
    }
    if (this->health <= 0)
    {
        this->health = 0;
    }
    if (this->health == 0)
    {
        if (this->isDie == false)
        {
            this->isDie = true;
            this->onHeroDie();
        }
    }
}

void Hero::onHeroDie()
{

}

void Hero::changeState(HeroBaseState* newState)
{
    this->activeState->onExit();
    CC_SAFE_DELETE(this->activeState);
    this->activeState = newState;
    this->activeState->onStart();
}

void Hero::initListener()
{
    // Init mouse listener
    auto mouseListener = EventListenerMouse::create();
    mouseListener->onMouseDown = CC_CALLBACK_1(Hero::onMouseDown, this);
    mouseListener->onMouseUp = CC_CALLBACK_1(Hero::onMouseUp, this);
    mouseListener->onMouseMove = CC_CALLBACK_1(Hero::onMouseMove, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);

    // Init keyboard listener
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(Hero::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(Hero::onKeyReleased, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void Hero::initHero()
{
    expList[0] = 10.f;
    for (auto i = 1; i < maxLevel; i++)
    {
        expList[i] = expList[i-1]* 0.25f;
    }
}

bool Hero::isWallContact()
{
    return this->wallContact;
}

void Hero::setWallContact(bool contact)
{
    this->wallContact = contact;
}
