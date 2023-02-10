#include "Enemy.h"
USING_NS_CC;

Enemy::Enemy():Entity()
{
    this->setTag(ENEMY_TAG);
}

Enemy::~Enemy()
{
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

void Enemy::entityShoot(std::function<void()> onFinish)
{
}

void Enemy::entityBehavior()
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

void Enemy::shooting()
{
}

void Enemy::setIsEntityShooting(bool value)
{
}

void Enemy::update(float dt)
{
}