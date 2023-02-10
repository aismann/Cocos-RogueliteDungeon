#ifndef __HERO_H__
#define __HERO_H__

#include "Entity.h"
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

    virtual int getExp();
    virtual void setExp(int exp);
    virtual int getLevel();
    virtual void setLevel(int level);
    virtual int getUpgradePoint();
    virtual void setUpgradePoint(int upgradepoint);

    virtual void setMaxHealth(float value);
    virtual float getHealth();
    virtual void setMaxShield(float value);
    virtual float getShield();
    virtual void setMaxDamage(float value);
    virtual float getDamage();
    virtual void setMaxAttackSpeed(float value);
    virtual float getAttackSpeed();
    virtual void setMaxMovementSpeed(float value);
    virtual float getMovementSpeed();

    virtual float getMaxHealth();
    virtual float getMaxShield();
    virtual float getMaxDamage();
    virtual float getMaxAttackSpeed();
    virtual float getMaxMovementSpeed();

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

    bool isWallContact();
    void setWallContact(bool contact);

protected:
    void changeState(HeroBaseState* newState);
    void initListener();
    void initHero();

    HeroJob heroJob;

    int exp = 0;
    int level = 1;
    int maxLevel = 100;
    float expList[100];
    int upgradepoint = 1;
    int scorepoint = 0;

    EntityStats maxHealth;
    float health;
    EntityStats maxShield;
    float shield;
    EntityStats maxDamage;
    float damage;
    EntityStats maxAttackSpeed;
    float attackSpeed;
    EntityStats maxMovementSpeed;
    float movementSpeed;

    cocos2d::Sprite* weaponNode;
    Weapon* weapon;

    HeroBaseState* activeState;

private:
    float xCoordinate;
    float yCoordinate;
    bool wallContact;
};

#endif // !__HERO_H__

