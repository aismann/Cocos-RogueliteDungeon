#ifndef __HERO_H__
#define __HERO_H__

#include "Entity.h"
//#include "ItemManager.h"
#include "HeroBaseState.h"
#include "Weapon.h"

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

    Weapon* getWeapon();
    cocos2d::Sprite* getWeaponNode();

    void update(float dt);

    void takeDamage(float damage);

protected:
    void changeState(HeroBaseState* newState);
    void initListener();
    void initHero();

    HeroJob heroJob;

    EntityStats maxHealth;
    float health;
    EntityStats maxShield;
    float shield;
    EntityStats maxDamage;
    float damage;
    EntityStats maxMovementSpeed;
    float movementSpeed;
    EntityStats maxPickupRange;
    float pickupRange;

    //ItemManager* itemManager;
    //std::vector<Weapon*> weaponSlot;
    cocos2d::Sprite* weaponNode;
    Weapon* weapon;

    HeroBaseState* activeState;

private:
    float xCoordinate;
    float yCoordinate;
};

#endif // !__HERO_H__

