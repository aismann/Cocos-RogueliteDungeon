#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "HeroManager.h"
#include "GameManager.h"
#include "cocos2d.h"
#include <cocos/ui/UIButton.h>
class GameScene : public cocos2d::Scene
{
private:
    bool m_contactStarted = false;
    bool isUpgradeHeroLayer = false;
    int healthPoint = 0;
    int shieldPoint = 0;
    int damagePoint = 0;
    int attackSpeedPoint = 0;
    int movementSpeedPoint = 0;

    float maxDanger = 100;
    float dangerPoint = 50;

    cocos2d::Vec2 lastMousePositon;
    cocos2d::TMXTiledMap* restroom;
    HeroManager* heroManager = Singleton<HeroManager>::getIntsance();
    GameManager* gameManager = Singleton<GameManager>::getIntsance();
    void initTileMap(cocos2d::Vec2 position);

    cocos2d::Node* playerHP;
    cocos2d::Node* playerSH;
    cocos2d::Node* expUI;
    cocos2d::Node* scoreUI;
    cocos2d::Node* dangerBarUI;
    cocos2d::Layer* upgradeHeroLayer;
    cocos2d::Layer* pauseMenuLayer;
    cocos2d::Camera* cameraUI;

    cocos2d::ui::Button* increaseHealthPointBtn;
    cocos2d::ui::Button* decreaseHealthPointBtn;
    cocos2d::ui::Button* increaseShieldPointBtn;
    cocos2d::ui::Button* decreaseShieldPointBtn;
    cocos2d::ui::Button* increaseDamagePointBtn;
    cocos2d::ui::Button* decreaseDamagePointBtn;
    cocos2d::ui::Button* increaseAttackSpeedPointBtn;
    cocos2d::ui::Button* decreaseAttackSpeedPointBtn;
    cocos2d::ui::Button* increaseMovementSpeedPointBtn;
    cocos2d::ui::Button* decreaseMovementSpeedPointBtn;
    cocos2d::ui::Button* applyBtn;

    void initPlayerInfo();
    void updatePlayerInfo(float dt);
    void initExpUI();
    void updateExpUI(float dt);
    void initScoreUI();
    void updateScoreUI(float dt);
    void initDangerBar();
    void updateDangerBar(float dt);
    void initPauseMenu();
    void initCameraUI();
    void initShowUpgradeHero();
    void updateShowUpgradeHero();
    void followHero();
    void isPauseEntity(bool value);
public:
    static cocos2d::Scene* createScene();
    bool onContactBegin(cocos2d::PhysicsContact& _contact);
    void onContactSeparate(cocos2d::PhysicsContact& _contact);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onMouseMove(cocos2d::Event* event);
    virtual bool init();
    void update(float dt);
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
