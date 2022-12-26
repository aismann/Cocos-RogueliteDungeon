#ifndef __HERO_H__
#define __HERO_H__

#include "Entity.h"
#include "ItemManager.h"
#include "HeroBaseState.h"

enum class HeroJob
{
    None = -1,
    Elf,
    Knight,
    Lizard,
    Wizard
};

class Hero : public Entity
{
public:
    Hero();
    ~Hero();

    HeroJob getHeroJob();

    float getXCoordinate();
    void setXCoordinate(float xCoord);
    float getYCoordinate();
    void setYCoordinate(float yCoord);

    virtual float getHealth();
    virtual float getShield();
    virtual float getDamage();
    virtual float getMovementSpeed();
    float getPickupRange();

    void pickupWeapon();
    void dropWeapon();
    void rotateWeaponByCursor(cocos2d::Vec2& location);

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onMouseDown(cocos2d::Event* event);
    void onMouseUp(cocos2d::Event* event);
    void onMouseMove(cocos2d::Event* event);

    void update(float dt);

protected:
    void changeState(HeroBaseState* newState);
    void initListener();
    void initHero();

    HeroJob heroJob;

    EntityStats health;
    EntityStats shield;
    EntityStats damage;
    EntityStats movementSpeed;
    EntityStats pickupRange;

    ItemManager* itemManager;
    std::vector<Weapon*> weaponSlot;
    cocos2d::Sprite* weaponNode;

    HeroBaseState* activeState;

private:
    float xCoordinate;
    float yCoordinate;
};

#endif // !__HERO_H__

