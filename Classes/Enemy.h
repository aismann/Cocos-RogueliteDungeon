#ifndef _ENEMY_H__
#define _ENEMY_H__
#include "Entity.h"
#include "Weapon.h"
enum Behavior
{
	None,
	Idle,
	Run,
	Attack,
	Skill
};
class Enemy:public Entity
{
protected:
	float distance = 0;
	Behavior currentBehavior = Behavior::None;
	Behavior nextBehavior = Behavior::None;
	EntityStats maxHealth;
	float health;
	EntityStats maxMana;
	float mana;
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
	bool isSkillActive = false;

public:
	Enemy();
	~Enemy();

	virtual void setEnemyAlived();
	virtual bool getIsDie();

	virtual void setMaxHealth(float value);
	virtual float getHealth();
	virtual void setMaxMana(float value);
	virtual float getMana();
	virtual void setMaxDamage(float value);
	virtual float getDamage();
	virtual void setMaxAttackSpeed(float value);
	virtual float getAttackSpeed();
	virtual void setMaxMovementSpeed(float value);
	virtual float getMovementSpeed();

	virtual float getMaxHealth();
	virtual float getMaxMana();
	virtual float getMaxDamage();
	virtual float getMaxAttackSpeed();
	virtual float getMaxMovementSpeed();

	virtual void takeDamage(float damage);
	virtual void entityIdle();
	virtual void entityRun();
	virtual void entityAttack(std::function<void()> onFinish);
	virtual void entitySkill(std::function<void()> onFinish);
	virtual void entityBehavior(float dt);
	virtual void entityDie();
	virtual void setIsEntityTakeDamage(bool value);
	virtual bool getIsEntityTakeDamage();
	virtual void setIsEntityRun(bool value);
	virtual bool getIsEntityRun();
	virtual void attacking();
	virtual void setIsEntityAttack(bool value);
	virtual void bossSkill();
	virtual void setIsEntitySkill(bool value);
	virtual void update(float dt);
private:

};
#endif // !_ENEMY_H__

