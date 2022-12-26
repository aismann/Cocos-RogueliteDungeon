#include "HeroAttackState.h"
#include "HeroIdleState.h"
USING_NS_CC;

#pragma region Run
void HeroAttackState::setAttackAnimation(Hero* hero)
{
	int frameBegin = 0;
	int frameEnd = 3;
	float frameDelay = 0.15f;
	switch (hero->getHeroJob())
	{
	case HeroJob::Elf:
		hero->setAnimation(REPEAT::FOREVER, ELF_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Knight:
		hero->setAnimation(REPEAT::FOREVER, KNIGHT_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Lizard:
		hero->setAnimation(REPEAT::FOREVER, LIZARD_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	case HeroJob::Wizard:
		hero->setAnimation(REPEAT::FOREVER, WIZARD_M_RUN, frameBegin, frameEnd, frameDelay);
		break;
	}
}
void HeroAttackState::onStart(Hero* hero)
{

	this->setAttackAnimation(hero);
}

void HeroAttackState::onExit(Hero* hero)
{


}

HeroBaseState* HeroAttackState::onKeyPressed(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		keyList.push_back(keycode);
		y_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		keyList.push_back(keycode);
		y_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		keyList.push_back(keycode);
		hero->setFlippedX(true);
		if (hero->getChildByTag(WEAPON_NODE_TAG)->getChildByTag(WEAPON_TAG))
		{
			dynamic_cast<Sprite*>(hero->getChildByTag(WEAPON_NODE_TAG)->getChildByTag(WEAPON_TAG))->setFlippedX(true);
		}
		x_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		keyList.push_back(keycode);
		hero->setFlippedX(false);
		if (hero->getChildByTag(WEAPON_NODE_TAG)->getChildByTag(WEAPON_TAG))
		{
			dynamic_cast<Sprite*>(hero->getChildByTag(WEAPON_NODE_TAG)->getChildByTag(WEAPON_TAG))->setFlippedX(false);
		}
		x_axist++;
		break;
	default:
		break;
	}
	it = std::find(keyList.begin(), keyList.end(), keycode);
	if (it != keyList.end())
	{
		if (*it == EventKeyboard::KeyCode::KEY_W
			|| *it == EventKeyboard::KeyCode::KEY_S
			|| *it == EventKeyboard::KeyCode::KEY_A
			|| *it == EventKeyboard::KeyCode::KEY_D)
		{
			hero->setSpeed(hero->getMovementSpeed());
			hero->setDirection(Vec2(x_axist, y_axist));
			return new HeroIdleState();
		}
	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroAttackState::onKeyReleased(Hero* hero, cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
#pragma region Movement
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		y_axist--;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		y_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		x_axist++;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		x_axist--;
		break;
	default:
		break;
	}
	it = std::find(keyList.begin(), keyList.end(), keycode);
	if (it != keyList.end())
	{
		if (*it == EventKeyboard::KeyCode::KEY_W
			|| *it == EventKeyboard::KeyCode::KEY_S
			|| *it == EventKeyboard::KeyCode::KEY_A
			|| *it == EventKeyboard::KeyCode::KEY_D)
		{
			keyList.erase(it);
			hero->setSpeed(hero->getMovementSpeed());
			hero->setDirection(Vec2(x_axist, y_axist));
			return new HeroIdleState();
		}
	}
#pragma endregion

	return nullptr;
}

HeroBaseState* HeroAttackState::onMouseDown(Hero* hero, cocos2d::Event* event)
{
	if (hero->getChildByTag(WEAPON_NODE_TAG)->getChildByTag(WEAPON_TAG))
	{
		auto weaponNode = dynamic_cast<Weapon*>(hero->getChildByTag(WEAPON_NODE_TAG)->getChildByTag(WEAPON_TAG));
		weaponNode->lightAttack();
	}
	return nullptr;
}

HeroBaseState* HeroAttackState::onMouseUp(Hero* hero, cocos2d::Event* event)
{
	return nullptr;
}

HeroBaseState* HeroAttackState::onMouseMove(Hero* hero, cocos2d::Event* event)
{
	EventMouse* e = (EventMouse*)event;
	this->lastMousePositon = e->getLocationInView();
	hero->rotateWeaponByCursor(this->lastMousePositon);
	return nullptr;
}

HeroBaseState* HeroAttackState::update(Hero* hero, float dt)
{
	if (hero->getChildByTag(WEAPON_NODE_TAG)->getChildByTag(WEAPON_TAG))
	{
		auto weaponNode = dynamic_cast<Weapon*>(hero->getChildByTag(WEAPON_NODE_TAG)->getChildByTag(WEAPON_TAG));
		weaponNode->update(dt);
	}
	return nullptr;
}

#pragma endregion