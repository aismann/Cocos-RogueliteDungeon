#ifndef __HERO_STATE_MANAGER_H__
#define __HERO_STATE_MANAGER_H__
#include "cocos2d.h"
#include "Singleton.h"
#include "HeroState.h"
class HeroStateManager
{
private:
	friend class Singleton<HeroStateManager>;
public:
	HeroBaseState* currentState;
	HeroIdleState* idleState = new HeroIdleState;
	HeroRunState* runState = new HeroRunState;
	HeroStateManager();
	~HeroStateManager();
	void update(float dt);
	HeroBaseState* getCurrentState();
	void switchState(HeroBaseState* state);
};

#endif // !__HERO_STATE_MANAGER_H__