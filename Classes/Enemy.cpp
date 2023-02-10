#include "Enemy.h"
#include "HeroManager.h"
USING_NS_CC;

Enemy::Enemy():Entity()
{
    this->setTag(ENEMY_TAG);
}

Enemy::~Enemy()
{
}

void Enemy::takeDamage(float damage)
{
    this->health -= damage;
    if (this->health <= 0)
    {
        this->health = 10;
        Singleton<HeroManager>::getIntsance()->getHero()->setExp(10);
    }
    log("Enemy HP [%f]", this->health);
}
