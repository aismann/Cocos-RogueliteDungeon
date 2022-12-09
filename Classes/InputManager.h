#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__
#include "cocos2d.h"
#include "Singleton.h"
class InputManager
{
private:
	friend class Singleton<InputManager>;

	/*Keyboard input*/

	cocos2d::EventKeyboard::KeyCode pauseMenu;
	cocos2d::EventKeyboard::KeyCode enter;
	cocos2d::EventKeyboard::KeyCode interact;

	cocos2d::EventKeyboard::KeyCode moveUp;
	cocos2d::EventKeyboard::KeyCode moveDown;
	cocos2d::EventKeyboard::KeyCode moveLeft;
	cocos2d::EventKeyboard::KeyCode moveRight;

	cocos2d::EventKeyboard::KeyCode dash;
	
	cocos2d::EventKeyboard::KeyCode itemSlot_1;
	cocos2d::EventKeyboard::KeyCode itemSlot_2;

	cocos2d::EventKeyboard::KeyCode skill_1;
	cocos2d::EventKeyboard::KeyCode skill_2;

	/*Mouse input*/

	cocos2d::EventMouse::MouseButton weaponAttack;
	cocos2d::EventMouse::MouseButton weaponSkill;
public:
	cocos2d::EventKeyboard::KeyCode getKeyPause();
	void setKeyPause(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyEnter();
	void setKeyEnter(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyInteract();
	void setKeyInteract(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyUp();
	void setKeyUp(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyDown();
	void setKeyDown(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyLeft();
	void setKeyLeft(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyRight();
	void setKeyRight(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyDash();
	void setKeyDash(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyItemOne();
	void setKeyItemOne(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeyItemTwo();
	void setKeyItemTwo(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeySkillOne();
	void setKeySkillOne(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventKeyboard::KeyCode getKeySkillTwo();
	void setKeySkillTwo(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventMouse::MouseButton getKeyWeaponAtack();
	void setKeyWeaponAtack(cocos2d::EventMouse::MouseButton code);
	cocos2d::EventMouse::MouseButton getKeyWeaponSkill();
	void setKeyWeaponSkill(cocos2d::EventMouse::MouseButton code);

	cocos2d::EventKeyboard::KeyCode getInput(cocos2d::EventKeyboard::KeyCode code);
	cocos2d::EventMouse::MouseButton getInput(cocos2d::EventMouse::MouseButton code);
};
#endif // !__INPUT_MANAGER_H__


