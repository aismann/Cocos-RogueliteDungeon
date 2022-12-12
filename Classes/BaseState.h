#ifndef __BASE_STATE_H__
#define __BASE_STATE_H__
#include "cocos2d.h"
template <typename T, typename U>
class BaseState
{
public:
	virtual U* onStart(T* _entity) = 0;
	virtual U* onExit(T* _entity) = 0;
	virtual U* onKeyPressed(T* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual U* onKeyReleased(T* _entity, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual U* update(T* _entity,float dt) = 0;
};
#endif // !__BASE_STATE_H__

