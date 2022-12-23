#ifndef __BASE_STATE_H__
#define __BASE_STATE_H__
#include "cocos2d.h"
template <typename T, typename U>
class BaseState
{
public:
	virtual void onStart(T* entity) = 0;
	virtual void onExit(T* entity) = 0;
	virtual U* onKeyPressed(T* entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual U* onKeyReleased(T* entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual U* onMouseDown(T* entity, cocos2d::Event* event) = 0;
	virtual U* onMouseUp(T* entity, cocos2d::Event* event) = 0;
	virtual U* onMouseMove(T* entity, cocos2d::Event* event) = 0;
	virtual U* update(T* entity, float dt) = 0;
};
#endif // !__BASE_STATE_H__

