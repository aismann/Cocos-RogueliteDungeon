#ifndef _ENEMY_H__
#define _ENEMY_H__
#include "Entity.h"
class Enemy:public Entity
{
protected:
	EntityStats maxHealth;
	float health = 100;
public:
	Enemy();
	~Enemy();
	void takeDamage(float damage);

private:

};
#endif // !_ENEMY_H__

