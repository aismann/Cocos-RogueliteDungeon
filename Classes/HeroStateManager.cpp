#include "HeroStateManager.h"

HeroStateManager::HeroStateManager()
{
	this->currentState = idleState;
}

HeroStateManager::~HeroStateManager()
{
}


void HeroStateManager::update(float dt)
{
	this->currentState->update(dt);
}

HeroBaseState* HeroStateManager::getCurrentState()
{
	return this->currentState;
}

void HeroStateManager::switchState(HeroBaseState* state)
{
	this->currentState = state;
}
