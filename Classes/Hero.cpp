#include "Hero.h"

USING_NS_CC;

void Hero::initHero()
{
    StatModifier* baseHP = new StatModifier(10, StatModifierType::Flat);
    this->health.addModifier(baseHP);
    StatModifier* baseMP = new StatModifier(5, StatModifierType::Flat, 0, this);
    this->shield.addModifier(baseMP);
    StatModifier* baseATK = new StatModifier(5, StatModifierType::Flat, 0, this);
    this->damage.addModifier(baseATK);
    StatModifier* basePickupRange = new StatModifier(100,StatModifierType::Flat,0,this);
    this->pickupRange.addModifier(basePickupRange);
}

Hero::Hero():Entity()
{
    this->heroJob = HeroJob::None;
    itemManager = Singleton<ItemManager>::getIntsance();
    this->initHero();
}

Hero::~Hero()
{
}
HeroJob Hero::getHeroJob()
{
    return this->heroJob;
}

float Hero::getHealth()
{
    return this->health.getValue();
}

float Hero::getShield()
{
    return this->shield.getValue();
}

float Hero::getDamage()
{
    return this->damage.getValue();
}

float Hero::getMovementSpeed()
{
    return this->movementSpeed.getValue();
}

float Hero::getPickupRange()
{
    return this->pickupRange.getValue();
}

void Hero::pickupWeapon()
{
    if (this->getChildByTag(WEAPON_NODE_TAG))
    {
        weaponNode = dynamic_cast<Sprite*>(this->getChildByTag(WEAPON_NODE_TAG));
    }
    if (weaponNode)
    {
        if (!itemManager->getItemList().empty())
        {
            std::vector<float> distance;
            for (auto& item : itemManager->getItemList())
            {
                distance.push_back(item->getPosition().distance(this->getPosition()));
            }

            int closestIndex = -1;
            float closestDistance = this->getPickupRange();
            for (size_t i = 0; i < itemManager->getItemList().size(); i++)
            {
                if (distance.at(i) <= closestDistance && itemManager->getItemList().at(i)->getTag() == WEAPON_TAG)
                {
                    closestIndex = i;
                    closestDistance = distance.at(i);
                }
            }

            if (closestIndex != -1)
            {
                if (weaponSlot.empty())
                {
                    auto item = itemManager->getItemList().at(closestIndex);
                    if (this->isFlippedX())
                    {
                        item->setFlippedX(true);
                    }
                    else
                    {
                        item->setFlippedX(false);
                    }
                    item->setPosition(weaponNode->getContentSize().width/2, weaponNode->getContentSize().height*(3.f/4.f));
                    itemManager->removeItem(item);
                    weaponSlot.push_back(item);
                    weaponNode->addChild(item);
                }
                else
                {
                    auto oldWeapon = weaponSlot.back();
                    weaponSlot.pop_back();

                    auto item = itemManager->getItemList().at(closestIndex);
                    if (this->isFlippedX())
                    {
                        item->setFlippedX(true);
                    }
                    else
                    {
                        item->setFlippedX(false);
                    }
                    item->setPosition(weaponNode->getContentSize().width/2, weaponNode->getContentSize().height*(3.f/4.f));
                    itemManager->removeItem(item);
                    weaponSlot.push_back(item);
                    weaponNode->addChild(item);

                    weaponNode->removeChild(oldWeapon, true);
                    oldWeapon->setPosition(this->getPosition());
                    itemManager->addItem(oldWeapon);
                }
            }
        }
    }
}

void Hero::dropWeapon()
{
    if (this->getChildByTag(WEAPON_NODE_TAG))
    {
        weaponNode = dynamic_cast<Sprite*>(this->getChildByTag(WEAPON_NODE_TAG));
    }
    if (weaponNode)
    {
        if (!weaponSlot.empty())
        {
            weaponNode->removeChild(weaponSlot.back(), true);
            weaponSlot.back()->setPosition(this->getPosition());
            itemManager->addItem(weaponSlot.back());
            weaponSlot.pop_back();
        }
    }
}

void Hero::rotateWeaponbyCursor(cocos2d::Vec2 location)
{
    if (this->getChildByTag(WEAPON_NODE_TAG))
    {
        weaponNode = dynamic_cast<Sprite*>(this->getChildByTag(WEAPON_NODE_TAG));
    }
    location = itemManager->getScene()->getDefaultCamera()->convertToWorldSpaceAR(location - itemManager->getVisibleSize() / 2);
    Vec2 aimDirection = location - this->getPosition();
    aimDirection.normalize();
    float radian = aimDirection.getAngle(Vec2(0, 1));
    float degree = radian * 180 / M_PI;
    weaponNode->setRotation(degree);
    if (weaponNode->getChildByTag(WEAPON_TAG))
    {
        if (degree < 0)
        {
            this->setFlippedX(true);
            dynamic_cast<Sprite*>(weaponNode->getChildByTag(WEAPON_TAG))->setFlippedX(true);
        }
        else
        {
            this->setFlippedX(false);
            dynamic_cast<Sprite*>(weaponNode->getChildByTag(WEAPON_TAG))->setFlippedX(false);
        }
    }
}

void Hero::update(float dt)
{
    if (!is)
    {
        //log("is");
        is = true;
    }
}
