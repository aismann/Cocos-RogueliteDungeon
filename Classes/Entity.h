#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Configs.h"
#include "EntityStats.h"
#include "GameResources.h"
enum class REPEAT
{
	FOREVER,
	ONCE
};
class Entity:public cocos2d::Sprite
{
private:
	std::string bodyFrameName;
	cocos2d::Vec2 direction;
	float speed;
protected:
	cocos2d::Animate* animate;
	cocos2d::Animation* animation;
	cocos2d::Animation* createAnimation(std::string _animate, int _begin, int _end, float _delay);
public:
	Entity();
	~Entity();
	void setSpriteFrame(std::string _framename, int _number);
	void setAnimation(REPEAT _repeat, std::string _animate, int _begin, int _end, float _delay);
	void setSpeedAndDirection(float speed, cocos2d::Vec2 direction);
	void update(float dt);
};
#endif // !__ENTITY_H__
