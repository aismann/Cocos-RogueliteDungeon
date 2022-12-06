#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#define SCALE_RATIO 32.0
enum class REPEAT
{
	FOREVER,
	ONCE
};
class Entity:public cocos2d::Sprite
{
private:
	Sprite* sprite;
protected:
	cocos2d::Animate* animate;
	cocos2d::Animation* animation;
	cocos2d::Animation* createAnimation(std::string _animate, int _begin, int _end, float _delay);
public:
	b2World* world;
	Entity();
	~Entity();
	void setSpriteFrame(std::string _framename, int _number);
	void setAnimation(REPEAT _repeat, std::string _animate, int _begin, int _end, float _delay);
	void update(float dt);
};
#endif // !__ENTITY_H__
