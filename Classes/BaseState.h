#ifndef __BASE_STATE_H__
#define __BASE_STATE_H__
#include "cocos2d.h"
template <typename T, typename U>
class BaseState
{
public:
	virtual void onStart() = 0;
	virtual void onExit() = 0;
	virtual U* onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual U* onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event) = 0;
	virtual U* onMouseDown(cocos2d::Event* event) = 0;
	virtual U* onMouseUp(cocos2d::Event* event) = 0;
	virtual U* onMouseMove(cocos2d::Event* event) = 0;
	virtual U* update(float dt) = 0;
};
#endif // !__BASE_STATE_H__

