#include "HeroBaseState.h"
USING_NS_CC;

Hero* HeroBaseState::hero;
std::vector<EventKeyboard::KeyCode> HeroBaseState::keyList;
std::vector<EventKeyboard::KeyCode>::iterator HeroBaseState::keyIt;
std::vector<cocos2d::EventMouse::MouseButton> HeroBaseState::buttonList;
std::vector<cocos2d::EventMouse::MouseButton>::iterator HeroBaseState::buttonIt;

void HeroBaseState::addHero(Hero* hero)
{
	this->hero = hero;
}
