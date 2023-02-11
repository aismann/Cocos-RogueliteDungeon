#include "Enemy.h"
USING_NS_CC;

Enemy::Enemy():Entity()
{
    this->setTag(ENEMY_TAG);
}

Enemy::~Enemy()
{
}

void Enemy::setEnemyAlived()
{

}

bool Enemy::getIsDie() 
{
    return this->isDie;
}

void Enemy::setMaxHealth(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxHealth.addModifier(baseValue);
    this->health = this->maxHealth.getValue();
}

float Enemy::getHealth()
{
    return this->health;
}

void Enemy::setMaxMana(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxMana.addModifier(baseValue);
    this->mana = this->maxMana.getValue();
}

float Enemy::getMana()
{
    return this->mana;
}

void Enemy::setMaxDamage(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxDamage.addModifier(baseValue);
    this->damage = this->maxDamage.getValue();
}

float Enemy::getDamage()
{
    return this->damage;
}

void Enemy::setMaxAttackSpeed(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxAttackSpeed.addModifier(baseValue);
    this->attackSpeed = this->maxAttackSpeed.getValue();
}

float Enemy::getAttackSpeed()
{
    return this->attackSpeed;
}

void Enemy::setMaxMovementSpeed(float value)
{
    StatModifier* baseValue = new StatModifier(value, StatModifierType::Flat, this);
    this->maxMovementSpeed.addModifier(baseValue);
    this->movementSpeed = this->maxMovementSpeed.getValue();
}

float Enemy::getMovementSpeed()
{
    return this->movementSpeed;
}

float Enemy::getMaxHealth()
{
    return this->maxHealth.getValue();
}

float Enemy::getMaxMana()
{
    return this->maxMana.getValue();
}

float Enemy::getMaxDamage()
{
    return this->maxDamage.getValue();
}

float Enemy::getMaxAttackSpeed()
{
    return this->maxAttackSpeed.getValue();
}

float Enemy::getMaxMovementSpeed()
{
    return this->maxMovementSpeed.getValue();
}

void Enemy::takeDamage(float damage)
{
}

void Enemy::entityIdle()
{
}

void Enemy::entityRun()
{
}

void Enemy::entityAttack(std::function<void()> onFinish)
{
}

void Enemy::entitySkill(std::function<void()> onFinish)
{
}

void Enemy::entityBehavior(float dt)
{
}

void Enemy::entityDie()
{
}

void Enemy::setIsEntityTakeDamage(bool value)
{
}

bool Enemy::getIsEntityTakeDamage()
{
    return false;
}

void Enemy::setIsEntityRun(bool value)
{
}

bool Enemy::getIsEntityRun()
{
    return false;
}

void Enemy::attacking()
{
}

void Enemy::setIsEntityAttack(bool value)
{
}

void Enemy::bossSkill()
{
}

void Enemy::setIsEntitySkill(bool value)
{
}

void Enemy::update(float dt)
{
}