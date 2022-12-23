#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "cocos2d.h"
#include "Configs.h"
#include "EntityStats.h"
#include "GameResources.h"
enum class REPEAT
{
	FOREVER,
	ONCE
};
class Entity :public cocos2d::Sprite
{
private:
	std::string spriteFrameName;
	cocos2d::Vec2 direction;
	float speed;

protected:
	cocos2d::Animate* animate;
	cocos2d::Animation* animation;
	cocos2d::Animation* createAnimation(std::string animationName, int startFrame, int endFrame, float frameDelay);

public:
	Entity();
	~Entity();

	static Entity* create();
	bool init() override;

	void setSpriteFrame(std::string frameName, int number, bool haveBody = true);
	void setAnimation(REPEAT repeat, std::string animationName, int startFrame, int endFrame, float frameDelay);

	cocos2d::Vec2 getDirection();
	void setDirection(cocos2d::Vec2 direction);

	float getSpeed();
	void setSpeed(float speed);

	virtual void update(float dt);
};
#endif // !__ENTITY_H__

