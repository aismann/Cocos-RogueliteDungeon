#include "Hero.h"
#include "HeroIdleState.h"
#include "GameManager.h"
USING_NS_CC;

Hero::Hero():Entity()
{
    this->setTag(HERO_TAG);
    this->xCoordinate = 0;
    this->yCoordinate = 0;

    this->heroJob = HeroJob::None;
    //this->itemManager = Singleton<ItemManager>::getIntsance();

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

float Hero::getHealth()
{
    return this->health;
}

float Hero::getShield()
{
    return this->shield;
}

float Hero::getDamage()
{
    return this->damage;
}

float Hero::getMovementSpeed()
{
    return this->movementSpeed;
}

float Hero::getPickupRange()
{
    return this->pickupRange;
}

void Hero::pickupWeapon()
{
    //if (this->getChildByTag(WEAPON_NODE_TAG))
    //{
    //    weaponNode = dynamic_cast<Sprite*>(this->getChildByTag(WEAPON_NODE_TAG));
    //}
    //if (weaponNode)
    //{
    //    if (!itemManager->getItemList().empty())
    //    {
    //        std::vector<float> distance;
    //        for (auto& item : itemManager->getItemList())
    //        {
    //            distance.push_back(item->getPosition().distance(this->getPosition()));
    //        }

    //        int closestIndex = -1;
    //        float closestDistance = this->getPickupRange();
    //        for (size_t i = 0; i < itemManager->getItemList().size(); i++)
    //        {
    //            if (distance.at(i) <= closestDistance && itemManager->getItemList().at(i)->getTag() == WEAPON_TAG)
    //            {
    //                closestIndex = i;
    //                closestDistance = distance.at(i);
    //            }
    //        }

    //        if (closestIndex != -1)
    //        {
    //            if (weaponSlot.empty())
    //            {
    //                auto item = itemManager->getItemList().at(closestIndex);
    //                if (this->isFlippedX())
    //                {
    //                    item->setFlippedX(true);
    //                }
    //                else
    //                {
    //                    item->setFlippedX(false);
    //                }
    //                item->setPosition(weaponNode->getContentSize().width/2, weaponNode->getContentSize().height*(3.f/4.f));
    //                itemManager->removeItem(item);
    //                weaponSlot.push_back(item);
    //                weaponNode->addChild(item);
    //            }
    //            else
    //            {
    //                auto oldWeapon = weaponSlot.back();
    //                weaponSlot.pop_back();

    //                auto item = itemManager->getItemList().at(closestIndex);
    //                if (this->isFlippedX())
    //                {
    //                    item->setFlippedX(true);
    //                }
    //                else
    //                {
    //                    item->setFlippedX(false);
    //                }
    //                item->setPosition(weaponNode->getContentSize().width/2, weaponNode->getContentSize().height*(3.f/4.f));
    //                itemManager->removeItem(item);
    //                weaponSlot.push_back(item);
    //                weaponNode->addChild(item);

    //                weaponNode->removeChild(oldWeapon, true);
    //                oldWeapon->setPosition(this->getPosition());
    //                itemManager->addItem(oldWeapon);
    //            }
    //        }
    //    }
    //}
}

void Hero::dropWeapon()
{
    //if (this->getChildByTag(WEAPON_NODE_TAG))
    //{
    //    weaponNode = dynamic_cast<Sprite*>(this->getChildByTag(WEAPON_NODE_TAG));
    //}
    //if (weaponNode)
    //{
    //    if (!weaponSlot.empty())
    //    {
    //        weaponNode->removeChild(weaponSlot.back(), true);
    //        weaponSlot.back()->setPosition(this->getPosition());
    //        itemManager->addItem(weaponSlot.back());
    //        weaponSlot.pop_back();
    //    }
    //}
}

void Hero::rotateWeaponByCursor(cocos2d::Vec2& location)
{
    location = Singleton<GameManager>::getIntsance()->getScene()->getDefaultCamera()->convertToWorldSpaceAR(location - Singleton<GameManager>::getIntsance()->getVisibleSize() / 2);
    Vec2 aimDirection = location - this->getPosition();
    aimDirection.normalize();
    float radian = aimDirection.getAngle(Vec2(0, 1));
    float degree = radian * 180 / M_PI;
    weaponNode->setRotation(degree);
    //if (degree < 0)
    //{
    //    this->setFlippedX(true);
    //    dynamic_cast<Sprite*>(weaponNode->getChildByTag(WEAPON_TAG))->setFlippedX(true);
    //}
    //else
    //{
    //    this->setFlippedX(false);
    //    dynamic_cast<Sprite*>(weaponNode->getChildByTag(WEAPON_TAG))->setFlippedX(false);
    //}
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
    else if (this->shield == 0)
    {
        this->health -= damage;
    }
    if (this->health <= 0)
    {
        this->health = 0;
    }
    log("Hero HP [%f]", this->health);
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

    StatModifier* baseHP = new StatModifier(10, StatModifierType::Flat);
    this->maxHealth.addModifier(baseHP);
    this->health = this->maxHealth.getValue();
    StatModifier* baseMP = new StatModifier(5, StatModifierType::Flat, 0, this);
    this->maxShield.addModifier(baseMP);
    this->shield = this->maxShield.getValue();
    StatModifier* baseATK = new StatModifier(5, StatModifierType::Flat, 0, this);
    this->maxDamage.addModifier(baseATK);
    this->damage = this->maxDamage.getValue();
    StatModifier* basePickupRange = new StatModifier(100, StatModifierType::Flat, 0, this);
    this->maxPickupRange.addModifier(basePickupRange);
    this->pickupRange = this->maxPickupRange.getValue();
}