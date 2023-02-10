#include "Bow.h"
#include "GameManager.h"
#include "HeroManager.h"
USING_NS_CC;

Bow::Bow():Weapon()
{
	this->setSpriteFrame(BOW, 0, false);
	this->setVisible(false);
}

Bow::~Bow()
{
}

void Bow::PrimarySkill(cocos2d::Sprite* weaponnode)
{
	float aimAngle = weaponnode->getRotation();
	Vec2 aimDirection = Vec2(0, 1);
	aimDirection.rotate(Vec2(0, 0), -aimAngle * M_PI / 180);

	Vec2 point1 = aimDirection;
	Vec2 point2 = aimDirection * 10;

	Vec2 point1WorldSpace = Singleton<GameManager>::getIntsance()->getScene()->convertToNodeSpace(weaponnode->getParent()->convertToWorldSpace(point1));
	Vec2 point2WorldSpace = Singleton<GameManager>::getIntsance()->getScene()->convertToNodeSpace(weaponnode->getParent()->convertToWorldSpace(point2));

	aimDirection = point2WorldSpace - point1WorldSpace;
	aimDirection.normalize();
	this->setVisible(true);
	shot = shotPool.getOnce();
	shot->setDamage(heroManager->getHero()->getDamage());
	shot->setLifeTime(5);
	Vec2 shotPos = Singleton<GameManager>::getIntsance()->getScene()->convertToNodeSpace(weaponnode->convertToWorldSpace(Vec2(weaponnode->getContentSize() / 2) + Vec2(0,10)));
	shot->setPosition(shotPos);
	shot->setRotation(aimAngle);
	auto speed = Singleton<HeroManager>::getIntsance()->getHero()->getMovementSpeed();
	shot->setSpeed(speed*1.5f);
	shot->setDirection(aimDirection);
	Singleton<GameManager>::getIntsance()->getScene()->addChild(shot);
	shotList.push_back(shot);
}

void Bow::setIsAttack(bool isAttack)
{
	if (isAttack)
	{
		auto attack = CallFunc::create([&]() {
			heroManager->getHero()->getWeapon()->PrimarySkill(heroManager->getHero()->getWeaponNode());
			});
		auto sequence = Sequence::create(attack, DelayTime::create(1.0 / heroManager->getHero()->getAttackSpeed()), nullptr);
		auto repeatAttack = RepeatForever::create(sequence);
		repeatAttack->setFlags(1);
		this->runAction(repeatAttack);
	}
	else
	{
		this->stopAllActions();
		this->setVisible(false);
	}

}

void Bow::update(float dt)
{
	std::list<BowShot*>::iterator it;
	std::list<BowShot*> removeArray;
	for (it = shotList.begin(); it != shotList.end(); ++it)
	{
		shot = *it;
		float life = shot->lifeTimeCouting(dt);
		shot->getPhysicsBody()->setRotationEnable(false);
		if (life <= 0)
		{
			Singleton<GameManager>::getIntsance()->getScene()->removeChild(shot);
			removeArray.push_back(shot);
			addToPool(shot);
		}
	}
	for (it = removeArray.begin(); it != removeArray.end(); ++it) {
		shotList.remove(*it);
	}
}

void Bow::addToPool(BowShot* shot)
{
	shot->getPhysicsBody()->setRotationEnable(true);
	this->shotPool.returnObject(shot);
}

