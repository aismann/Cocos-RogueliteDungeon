#ifndef _ENEMY_H__
#define _ENEMY_H__
#include "Entity.h"
enum Behavior
{
	None,
	Idle,
	Run,
	Attack,
	Shoot
};
class Enemy:public Entity
{
protected:
	float distance = 0;
	Behavior currentBehavior = Behavior::None;
	Behavior nextBehavior = Behavior::None;
	EntityStats maxHealth;
	float health;
	EntityStats maxDamage;
	float damage;
	EntityStats maxAttackSpeed;
	float attackSpeed;
	EntityStats maxMovementSpeed;
	float movementSpeed;
	bool isDie = false;
	bool isTakeDamage = false;
	bool isRun = false;
	bool isIdleActive = false;
	bool isRunActive = false;
	bool isAttackActive = false;
	bool isShootingActive = false;

public:
	Enemy();
	~Enemy();

	virtual void setMaxHealth(float value);
	virtual float getHealth();
	virtual void setMaxDamage(float value);
	virtual float getDamage();
	virtual void setMaxAttackSpeed(float value);
	virtual float getAttackSpeed();
	virtual void setMaxMovementSpeed(float value);
	virtual float getMovementSpeed();

	virtual void takeDamage(float damage);
	virtual void entityIdle();
	virtual void entityRun();
	virtual void entityAttack(std::function<void()> onFinish);
	virtual void entityShoot(std::function<void()> onFinish);
	virtual void entityBehavior();
	virtual void entityDie();
	virtual void setIsEntityTakeDamage(bool value);
	virtual bool getIsEntityTakeDamage();
	virtual void setIsEntityRun(bool value);
	virtual bool getIsEntityRun();
	virtual void attacking();
	virtual void setIsEntityAttack(bool value);
	virtual void shooting();
	virtual void setIsEntityShooting(bool value);
	virtual void update(float dt);
private:

};
#endif // !_ENEMY_H__

