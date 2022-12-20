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
class Entity:public cocos2d::Node
{
private:
	std::string frameName;
	cocos2d::Vec2 direction;
	float speed;
protected:
	cocos2d::Animate* animate;
	cocos2d::Animation* animation;
	cocos2d::Animation* createAnimation(std::string animationName, int startFrame, int endFrame, float frameDelay);
public:
	Entity();
	~Entity();
	void setSpriteFrame(std::string frameName, int number, bool haveBody = true);
	void setAnimation(REPEAT repeat, std::string animationName, int startFrame, int endFrame, float frameDelay);
	std::string getFrameName();
	cocos2d::Vec2 getEntityDirection();
	void setEntityDirection(cocos2d::Vec2 direction);
	float getEntitySpeed();
	void setEntitySpeed(float speed);
	void update(float dt);
};
#endif // !__ENTITY_H__
