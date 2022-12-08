#include "InputManager.h"
USING_NS_CC;

cocos2d::EventKeyboard::KeyCode InputManager::getKeyPause()
{
	return this->pauseMenu;
}

void InputManager::setKeyPause(cocos2d::EventKeyboard::KeyCode code)
{
	this->pauseMenu = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyEnter()
{
	return this->enter;
}

void InputManager::setKeyEnter(cocos2d::EventKeyboard::KeyCode code)
{
	this->enter = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyInteract()
{
	return this->interact;
}

void InputManager::setKeyInteract(cocos2d::EventKeyboard::KeyCode code)
{
	this->interact = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyUp()
{
	return this->moveUp;
}

void InputManager::setKeyUp(cocos2d::EventKeyboard::KeyCode code)
{
	this->moveUp = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyDown()
{
	return this->moveDown;
}

void InputManager::setKeyDown(cocos2d::EventKeyboard::KeyCode code)
{
	this->moveDown = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyLeft()
{
	return this->moveLeft;
}

void InputManager::setKeyLeft(cocos2d::EventKeyboard::KeyCode code)
{
	this->moveLeft = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyRight()
{
	return this->moveRight;
}

void InputManager::setKeyRight(cocos2d::EventKeyboard::KeyCode code)
{
	this->moveRight = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyDash()
{
	return this->dash;
}

void InputManager::setKeyDash(cocos2d::EventKeyboard::KeyCode code)
{
	this->dash = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyItemOne()
{
	return this->itemSlot_1;
}

void InputManager::setKeyItemOne(cocos2d::EventKeyboard::KeyCode code)
{
	this->itemSlot_1 = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeyItemTwo()
{
	return this->itemSlot_2;
}

void InputManager::setKeyItemTwo(cocos2d::EventKeyboard::KeyCode code)
{
	this->itemSlot_2 = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeySkillOne()
{
	return this->skill_1;
}

void InputManager::setKeySkillOne(cocos2d::EventKeyboard::KeyCode code)
{
	this->skill_1 = code;
}

cocos2d::EventKeyboard::KeyCode InputManager::getKeySkillTwo()
{
	return this->skill_2;
}

void InputManager::setKeySkillTwo(cocos2d::EventKeyboard::KeyCode code)
{
	this->skill_2 = code;
}

cocos2d::EventMouse::MouseButton InputManager::getKeyWeaponAtack()
{
	return this->weaponAttack;
}

void InputManager::setKeyWeaponAtack(cocos2d::EventMouse::MouseButton code)
{
	this->weaponAttack = code;
}

cocos2d::EventMouse::MouseButton InputManager::getKeyWeaponSkill()
{
	return this->weaponSkill;
}

void InputManager::setKeyWeaponSkill(cocos2d::EventMouse::MouseButton code)
{
	this->weaponSkill = code;
}
