#include "Sword.h"
#include "GameManager.h"
#include "HeroManager.h"
USING_NS_CC;
void Sword::initWeapon()
{
}

Sword::Sword():Weapon()
{
	this->initWeapon();
	this->setSpriteFrame(SWORD,0,false);
}

Sword::~Sword()
{
}

void Sword::PrimarySkill(cocos2d::Sprite* weaponnode)
{
	if (!this->primarySkill)
	{
		this->primarySkill = true;
		float aimAngle = weaponnode->getRotation();
		Vec2 aimDirection = Vec2(0, 1);
		aimDirection.rotate(Vec2(0, 0), -aimAngle * M_PI / 180);

		Vec2 point1 = aimDirection;
		Vec2 point2 = aimDirection * 10;

		Vec2 point1WorldSpace = Singleton<GameManager>::getIntsance()->getScene()->convertToNodeSpace(weaponnode->getParent()->convertToWorldSpace(point1));
		Vec2 point2WorldSpace = Singleton<GameManager>::getIntsance()->getScene()->convertToNodeSpace(weaponnode->getParent()->convertToWorldSpace(point2));

		aimDirection = point2WorldSpace - point1WorldSpace;
		aimDirection.normalize();

		slash = slashPool.getOnce();
		slash->setScale(2.f);
		slash->setLifeTime(0.6f);
		Vec2 slashPos = Singleton<GameManager>::getIntsance()->getScene()->convertToNodeSpace(weaponnode->convertToWorldSpace(weaponnode->getContentSize() / 2));
		slash->setPosition(slashPos);
		slash->setRotation(aimAngle);
		auto speed = Singleton<HeroManager>::getIntsance()->getHero()->getMovementSpeed();
		slash->setSpeed(speed);
		Singleton<GameManager>::getIntsance()->getScene()->addChild(slash);
		slashList.push_back(slash);
	}
}

void Sword::update(float dt)
{
	if (this->primarySkill)
	{
		this->timeElapsed += dt;
		float primaryAttackSpeed = 1.0 / 2.5;
		if (this->timeElapsed >= primaryAttackSpeed)
		{
			this->timeElapsed = 0.0;
			this->primarySkill = false;
		}
	}
	std::list<SwordSlash*>::iterator it;
	std::list<SwordSlash*> removeArray;
	for (it = slashList.begin(); it != slashList.end(); ++it)
	{
		slash = *it;
		float life = slash->lifeTimeCouting(dt);

		auto hero = Singleton<HeroManager>::getIntsance()->getHero();
		auto heroPos = hero->getPosition();
		slash->setPosition(Vec2(heroPos.x, heroPos.y + hero->getContentSize().height / 4));

		if (life <= 0)
		{
			Singleton<GameManager>::getIntsance()->getScene()->removeChild(slash);
			removeArray.push_back(slash);
			addToPool(slash);
		}
	}
	for (it = removeArray.begin(); it != removeArray.end(); ++it) {
		slashList.remove(*it);
	}
}

void Sword::addToPool(SwordSlash* slash)
{
	this->slashPool.returnObject(slash);
}

