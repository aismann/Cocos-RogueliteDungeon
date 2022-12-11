#ifndef __BASE_STATE_H__
#define __BASE_STATE_H__
#include "cocos2d.h"
template <typename T>
class BaseState
{
public:
	virtual void onStart(T* _entity) = 0;
	virtual void onExit(T* _entity) = 0;
	virtual void onKeyPressed(T* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual void onKeyReleased(T* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual void update(T* _entity,float dt) = 0;
};
#endif // !__BASE_STATE_H__

