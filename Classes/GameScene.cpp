#include "GameScene.h"
#include "PhysicsShapeCache.h"
#include "SwordSlash.h"
#include "BowShot.h"
#include "Skeleton.h"
USING_NS_CC;

void GameScene::initTileMap(cocos2d::Vec2 position)
{
    this->restroom = TMXTiledMap::create("maps/dungeon.tmx");
    this->restroom->setPosition(Vec2(position.x*0.5,position.y*0.5));
    this->restroom->setAnchorPoint(Vec2(0.5,0.5));
    this->restroom->setScaleX(((120*16)/this->restroom->getContentSize().width));
    this->restroom->setScaleY(((68*16)/this->restroom->getContentSize().height));
    this->addChild(this->restroom,-1);

    auto objectGroup = this->restroom->getObjectGroup("WallCollision");
    for (auto &object: objectGroup->getObjects())
    {
        auto properties = object.asValueMap();
        auto x = properties.at("x").asInt() + properties.at("width").asInt()/2;
        auto y = properties.at("y").asInt() + properties.at("height").asInt() / 2;
        auto objectSize = Size(properties.at("width").asInt(), properties.at("height").asInt());
        auto wallBody = PhysicsBody::createBox(objectSize, PhysicsMaterial(1.0f, 0.0f, 0.0f));
        wallBody->setDynamic(false);
        wallBody->setContactTestBitmask(0xffff);
        wallBody->setCategoryBitmask(64);
        wallBody->setContactTestBitmask(51);
        auto wallNode = Node::create();
        wallNode->setTag(WALL_TAG);
        wallNode->setPosition(x, y);
        wallNode->setPhysicsBody(wallBody);
        wallNode->setContentSize(objectSize);
        this->restroom->addChild(wallNode,2);
    }
}

void GameScene::initPlayerInfo()
{
    this->playerHP = Node::create();
    playerHP->setAnchorPoint(Vec2(0, 0.5));

    Sprite* hpBarBG = Sprite::create("ui/hpBarBG.png");
    hpBarBG->setName("hpBarBG");
    hpBarBG->setContentSize(Size(200, 20));
    hpBarBG->setAnchorPoint(Vec2(0, 0.5));

    Sprite* hpBar = Sprite::create("ui/hpBar.png");
    hpBar->setName("hpBar");
    hpBar->setContentSize(Size(200, 20));
    hpBar->setAnchorPoint(Vec2(0, 0.5));

    this->playerSH = Node::create();
    playerSH->setAnchorPoint(Vec2(1,0.5));

    Sprite* shieldBarBG = Sprite::create("ui/shieldBarBG.png");
    shieldBarBG->setName("shieldBarBG");
    shieldBarBG->setContentSize(Size(200, 20));
    shieldBarBG->setAnchorPoint(Vec2(1, 0.5));

    Sprite* shieldBar = Sprite::create("ui/shieldBar.png");
    shieldBar->setName("shieldBar");
    shieldBar->setContentSize(Size(200, 20));
    shieldBar->setAnchorPoint(Vec2(1,0.5));

    playerHP->addChild(hpBarBG);
    playerHP->addChild(hpBar);

    playerSH->addChild(shieldBarBG);
    playerSH->addChild(shieldBar);

    playerHP->setPosition(Vec2(gameManager->getVisibleSize().width * 0.01, gameManager->getVisibleSize().height * 0.05));
    playerSH->setPosition(Vec2(this->playerHP->getPosition().x + shieldBar->getContentSize().width, this->playerHP->getPosition().y));

    this->addChild(playerHP);
    this->addChild(playerSH);

    this->playerHP->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->playerSH->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
}

void GameScene::updatePlayerInfo(float dt)
{
    auto* hpBarBG = this->playerHP->getChildByName("hpBarBG");
    auto* hpBar = this->playerHP->getChildByName("hpBar");
    auto* shieldBarBG = this->playerSH->getChildByName("shieldBarBG");
    auto* shieldBar = this->playerSH->getChildByName("shieldBar");
    auto* player = heroManager->getHero();

    Size hpBarSize = hpBar->getContentSize();
    Size shieldBarSize = shieldBar->getContentSize();

    float speed = 1.5f;
    float newHP = player->getHealth() / player->getMaxHealth()
        * hpBarBG->getContentSize().width;
    float newShield = player->getShield() / player->getMaxShield()
        * shieldBarBG->getContentSize().width;
    hpBarSize.width = MathUtil::lerp(hpBarSize.width, newHP, dt * speed);
    shieldBarSize.width = MathUtil::lerp(shieldBarSize.width,newShield, dt* speed);
    hpBar->setContentSize(hpBarSize);
    shieldBar->setContentSize(shieldBarSize);
}

void GameScene::initExpUI()
{

}

void GameScene::updateExpUI(float dt)
{

}

void GameScene::initCameraUI()
{
    this->cameraUI = Camera::create();
    this->cameraUI->setCameraFlag(CameraFlag::USER2);
    this->addChild(cameraUI);
}

void GameScene::initShowUpgradeHero()
{
    this->upgradeHeroLayer = LayerColor::create(Color4B::BLACK);
    this->upgradeHeroLayer->setOpacity(170);
    this->upgradeHeroLayer->setContentSize(Size(600,400));
    Size layerSize = this->upgradeHeroLayer->getContentSize();
    this->upgradeHeroLayer->setPosition(gameManager->getVisibleSize().width/2 - layerSize.width/2
        , gameManager->getVisibleSize().height/2 - layerSize.height / 2);
    this->upgradeHeroLayer->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->setVisible(false);
    this->addChild(this->upgradeHeroLayer);

    const int marginLeft = 80;

    Label* statLabel = Label::createWithTTF("STATS", "fonts/dogicapixel.ttf", 40);
    statLabel->setTextColor(Color4B::WHITE);
    statLabel->setPosition(layerSize.width * 0.5f, layerSize.height * 0.85f);
    statLabel->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(statLabel);

    Label* hpLabel = Label::createWithTTF("Health : ", "fonts/dogicapixel.ttf", 20);
    hpLabel->setTextColor(Color4B::RED);
    hpLabel->setPosition(layerSize.width*0.35f,layerSize.height*0.7f);
    hpLabel->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(hpLabel);

    Label* hpValue = Label::createWithTTF("0", "fonts/dogicapixel.ttf", 20);
    hpValue->setAnchorPoint(Vec2(0,0.5));
    hpValue->setName("hpValue");
    hpValue->setTextColor(Color4B::RED);
    hpValue->setPosition(layerSize.width * 0.35f + marginLeft, layerSize.height * 0.7f);
    hpValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(hpValue);

    Label* shLabel = Label::createWithTTF("Shield : ", "fonts/dogicapixel.ttf", 20);
    shLabel->setTextColor(Color4B::BLUE);
    shLabel->setPosition(layerSize.width * 0.35f, layerSize.height * 0.6f);
    shLabel->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(shLabel);

    Label* shValue = Label::createWithTTF("0", "fonts/dogicapixel.ttf", 20);
    shValue->setAnchorPoint(Vec2(0, 0.5));
    shValue->setName("shValue");
    shValue->setTextColor(Color4B::BLUE);
    shValue->setPosition(layerSize.width * 0.35f + marginLeft, layerSize.height * 0.6f);
    shValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(shValue);

    Label* atkLabel = Label::createWithTTF("Damage : ", "fonts/dogicapixel.ttf", 20);
    atkLabel->setTextColor(Color4B::YELLOW);
    atkLabel->setPosition(layerSize.width * 0.336f, layerSize.height * 0.5f);
    atkLabel->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(atkLabel);

    Label* atkValue = Label::createWithTTF("0", "fonts/dogicapixel.ttf", 20);
    atkValue->setAnchorPoint(Vec2(0, 0.5));
    atkValue->setName("atkValue");
    atkValue->setTextColor(Color4B::YELLOW);
    atkValue->setPosition(layerSize.width * 0.35f + marginLeft, layerSize.height * 0.5f);
    atkValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(atkValue);

    Label* aspLabel = Label::createWithTTF("AtkSpd : ", "fonts/dogicapixel.ttf", 20);
    aspLabel->setTextColor(Color4B::GREEN);
    aspLabel->setPosition(layerSize.width * 0.344f, layerSize.height * 0.4f);
    aspLabel->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(aspLabel);

    Label* aspValue = Label::createWithTTF("0", "fonts/dogicapixel.ttf", 20);
    aspValue->setAnchorPoint(Vec2(0, 0.5));
    aspValue->setName("aspValue");
    aspValue->setTextColor(Color4B::GREEN);
    aspValue->setPosition(layerSize.width * 0.35f + marginLeft, layerSize.height * 0.4f);
    aspValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(aspValue);

    Label* mspLabel = Label::createWithTTF("MovSpd : ", "fonts/dogicapixel.ttf", 20);
    mspLabel->setTextColor(Color4B::WHITE);
    mspLabel->setPosition(layerSize.width * 0.338f, layerSize.height * 0.3f);
    mspLabel->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(mspLabel);

    Label* mspValue = Label::createWithTTF("0", "fonts/dogicapixel.ttf", 20);
    mspValue->setAnchorPoint(Vec2(0, 0.5));
    mspValue->setName("mspValue");
    mspValue->setTextColor(Color4B::WHITE);
    mspValue->setPosition(layerSize.width * 0.35f + marginLeft, layerSize.height * 0.3f);
    mspValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(mspValue);

    Label* upgradePointLabel = Label::createWithTTF("Point : ", "fonts/dogicapixel.ttf", 20);
    upgradePointLabel->setTextColor(Color4B::WHITE);
    upgradePointLabel->setPosition(layerSize.width * 0.35f, layerSize.height * 0.2f);
    upgradePointLabel->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(upgradePointLabel);

    Label* upgradePointValue = Label::createWithTTF("0", "fonts/dogicapixel.ttf", 20);
    upgradePointValue->setAnchorPoint(Vec2(0, 0.5));
    upgradePointValue->setName("upgradePointValue");
    upgradePointValue->setTextColor(Color4B::WHITE);
    upgradePointValue->setPosition(layerSize.width * 0.35f + marginLeft, layerSize.height * 0.2f);
    upgradePointValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(upgradePointValue);

    /*---*/

    Label* upgradeHealthValue = Label::createWithTTF(std::to_string(healthPoint), "fonts/dogicapixel.ttf", 20);
    upgradeHealthValue->setAnchorPoint(Vec2(0, 0.5));
    upgradeHealthValue->setName("upgradeHealthValue");
    upgradeHealthValue->setTextColor(Color4B::WHITE);
    upgradeHealthValue->setPosition(layerSize.width * 0.45f + marginLeft * 3, layerSize.height * 0.7f);
    upgradeHealthValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(upgradeHealthValue);

    Label* upgradeShieldValue = Label::createWithTTF(std::to_string(shieldPoint), "fonts/dogicapixel.ttf", 20);
    upgradeShieldValue->setAnchorPoint(Vec2(0, 0.5));
    upgradeShieldValue->setName("upgradeShieldValue");
    upgradeShieldValue->setTextColor(Color4B::WHITE);
    upgradeShieldValue->setPosition(layerSize.width * 0.45f + marginLeft * 3, layerSize.height * 0.6f);
    upgradeShieldValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(upgradeShieldValue);

    Label* upgradeDamageValue = Label::createWithTTF(std::to_string(damagePoint), "fonts/dogicapixel.ttf", 20);
    upgradeDamageValue->setAnchorPoint(Vec2(0, 0.5));
    upgradeDamageValue->setName("upgradeDamageValue");
    upgradeDamageValue->setTextColor(Color4B::WHITE);
    upgradeDamageValue->setPosition(layerSize.width * 0.45f + marginLeft * 3, layerSize.height * 0.5f);
    upgradeDamageValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(upgradeDamageValue);

    Label* upgradeAttackSpeedValue = Label::createWithTTF(std::to_string(attackSpeedPoint), "fonts/dogicapixel.ttf", 20);
    upgradeAttackSpeedValue->setAnchorPoint(Vec2(0, 0.5));
    upgradeAttackSpeedValue->setName("upgradeAttackSpeedValue");
    upgradeAttackSpeedValue->setTextColor(Color4B::WHITE);
    upgradeAttackSpeedValue->setPosition(layerSize.width * 0.45f + marginLeft * 3, layerSize.height * 0.4f);
    upgradeAttackSpeedValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(upgradeAttackSpeedValue);

    Label* upgradeMovementSpeedValue = Label::createWithTTF(std::to_string(movementSpeedPoint), "fonts/dogicapixel.ttf", 20);
    upgradeMovementSpeedValue->setAnchorPoint(Vec2(0, 0.5));
    upgradeMovementSpeedValue->setName("upgradeMovementSpeedValue");
    upgradeMovementSpeedValue->setTextColor(Color4B::WHITE);
    upgradeMovementSpeedValue->setPosition(layerSize.width * 0.45f + marginLeft * 3, layerSize.height * 0.3f);
    upgradeMovementSpeedValue->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->upgradeHeroLayer->addChild(upgradeMovementSpeedValue);

    this->increaseHealthPointBtn = ui::Button::create("ui/increaseicon1.png", "ui/increaseicon2.png", "ui/increaseicon3.png");
    this->decreaseHealthPointBtn = ui::Button::create("ui/decreaseicon1.png", "ui/decreaseicon2.png", "ui/decreaseicon3.png");
    this->increaseShieldPointBtn = ui::Button::create("ui/increaseicon1.png", "ui/increaseicon2.png", "ui/increaseicon3.png");
    this->decreaseShieldPointBtn = ui::Button::create("ui/decreaseicon1.png", "ui/decreaseicon2.png", "ui/decreaseicon3.png");
    this->increaseDamagePointBtn = ui::Button::create("ui/increaseicon1.png", "ui/increaseicon2.png", "ui/increaseicon3.png");
    this->decreaseDamagePointBtn = ui::Button::create("ui/decreaseicon1.png", "ui/decreaseicon2.png", "ui/decreaseicon3.png");
    this->increaseAttackSpeedPointBtn = ui::Button::create("ui/increaseicon1.png", "ui/increaseicon2.png", "ui/increaseicon3.png");
    this->decreaseAttackSpeedPointBtn = ui::Button::create("ui/decreaseicon1.png", "ui/decreaseicon2.png", "ui/decreaseicon3.png");
    this->increaseMovementSpeedPointBtn = ui::Button::create("ui/increaseicon1.png", "ui/increaseicon2.png", "ui/increaseicon3.png");
    this->decreaseMovementSpeedPointBtn = ui::Button::create("ui/decreaseicon1.png", "ui/decreaseicon2.png", "ui/decreaseicon3.png");

    this->applyBtn = ui::Button::create("ui/button1.png", "ui/button2.png", "ui/button3.png");
    this->applyBtn->setScale9Enabled(true);
    this->applyBtn->setScale(2);
    this->applyBtn->setTitleFontName("fonts/dogicapixel.ttf");
    this->applyBtn->setTitleFontSize(14);
    this->applyBtn->setTitleText("Apply");

    this->increaseHealthPointBtn->setPosition(Vec2(layerSize.width * 0.4f + marginLeft * 3, layerSize.height * 0.7f));
    this->decreaseHealthPointBtn->setPosition(Vec2(layerSize.width * 0.35f + marginLeft * 3, layerSize.height * 0.7f));
    this->increaseShieldPointBtn->setPosition(Vec2(layerSize.width * 0.4f + marginLeft * 3, layerSize.height * 0.6f));
    this->decreaseShieldPointBtn->setPosition(Vec2(layerSize.width * 0.35f + marginLeft * 3, layerSize.height * 0.6f));
    this->increaseDamagePointBtn->setPosition(Vec2(layerSize.width * 0.4f + marginLeft * 3, layerSize.height * 0.5f));
    this->decreaseDamagePointBtn->setPosition(Vec2(layerSize.width * 0.35f + marginLeft * 3, layerSize.height * 0.5f));
    this->increaseAttackSpeedPointBtn->setPosition(Vec2(layerSize.width * 0.4f + marginLeft * 3, layerSize.height * 0.4f));
    this->decreaseAttackSpeedPointBtn->setPosition(Vec2(layerSize.width * 0.35f + marginLeft * 3, layerSize.height * 0.4f));
    this->increaseMovementSpeedPointBtn->setPosition(Vec2(layerSize.width * 0.4f + marginLeft * 3, layerSize.height * 0.3f));
    this->decreaseMovementSpeedPointBtn->setPosition(Vec2(layerSize.width * 0.35f + marginLeft * 3, layerSize.height * 0.3f));

    this->applyBtn->setPosition(Vec2(layerSize.width * 0.35f + marginLeft * 3, layerSize.height * 0.2f));

    this->increaseHealthPointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->decreaseHealthPointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->increaseShieldPointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->decreaseShieldPointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->increaseDamagePointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->decreaseDamagePointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->increaseAttackSpeedPointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->decreaseAttackSpeedPointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->increaseMovementSpeedPointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());
    this->decreaseMovementSpeedPointBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());

    this->applyBtn->setCameraMask((unsigned short)this->cameraUI->getCameraFlag());

    this->upgradeHeroLayer->addChild(this->increaseHealthPointBtn);
    this->upgradeHeroLayer->addChild(this->decreaseHealthPointBtn);
    this->upgradeHeroLayer->addChild(this->increaseShieldPointBtn);
    this->upgradeHeroLayer->addChild(this->decreaseShieldPointBtn);
    this->upgradeHeroLayer->addChild(this->increaseDamagePointBtn);
    this->upgradeHeroLayer->addChild(this->decreaseDamagePointBtn);
    this->upgradeHeroLayer->addChild(this->increaseAttackSpeedPointBtn);
    this->upgradeHeroLayer->addChild(this->decreaseAttackSpeedPointBtn);
    this->upgradeHeroLayer->addChild(this->increaseMovementSpeedPointBtn);
    this->upgradeHeroLayer->addChild(this->decreaseMovementSpeedPointBtn);
    
    this->upgradeHeroLayer->addChild(this->applyBtn);

    this->increaseHealthPointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() > 0 && healthPoint >= 0)
            {
                Node* healthValue = this->upgradeHeroLayer->getChildByName("upgradeHealthValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    healthPoint += 1;
                    ((Label*)healthValue)->setString(std::to_string(healthPoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() - 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->decreaseHealthPointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() >= 0 && healthPoint > 0)
            {
                Node* healthValue = this->upgradeHeroLayer->getChildByName("upgradeHealthValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    healthPoint -= 1;
                    ((Label*)healthValue)->setString(std::to_string(healthPoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() + 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->increaseShieldPointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() > 0 && shieldPoint >= 0)
            {
                Node* shieldValue = this->upgradeHeroLayer->getChildByName("upgradeShieldValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    shieldPoint += 1;
                    ((Label*)shieldValue)->setString(std::to_string(shieldPoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() - 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->decreaseShieldPointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() >= 0 && shieldPoint > 0)
            {
                Node* shieldValue = this->upgradeHeroLayer->getChildByName("upgradeShieldValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    shieldPoint -= 1;
                    ((Label*)shieldValue)->setString(std::to_string(shieldPoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() + 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->increaseDamagePointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() > 0 && damagePoint >= 0)
            {
                Node* damageValue = this->upgradeHeroLayer->getChildByName("upgradeDamageValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    damagePoint += 1;
                    ((Label*)damageValue)->setString(std::to_string(damagePoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() - 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->decreaseDamagePointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() >= 0 && damagePoint > 0)
            {
                Node* damageValue = this->upgradeHeroLayer->getChildByName("upgradeDamageValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    damagePoint -= 1;
                    ((Label*)damageValue)->setString(std::to_string(damagePoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() + 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->increaseAttackSpeedPointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() > 0 && attackSpeedPoint >= 0)
            {
                Node* attackSpeedValue = this->upgradeHeroLayer->getChildByName("upgradeAttackSpeedValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    attackSpeedPoint += 1;
                    ((Label*)attackSpeedValue)->setString(std::to_string(attackSpeedPoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() - 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->decreaseAttackSpeedPointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() >= 0 && attackSpeedPoint > 0)
            {
                Node* attackSpeedValue = this->upgradeHeroLayer->getChildByName("upgradeAttackSpeedValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    attackSpeedPoint -= 1;
                    ((Label*)attackSpeedValue)->setString(std::to_string(attackSpeedPoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() + 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->increaseMovementSpeedPointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() > 0 && movementSpeedPoint >= 0)
            {
                Node* movementSpeedValue = this->upgradeHeroLayer->getChildByName("upgradeMovementSpeedValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    movementSpeedPoint += 1;
                    ((Label*)movementSpeedValue)->setString(std::to_string(movementSpeedPoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() - 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });
    this->decreaseMovementSpeedPointBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            if (heroManager->getHero()->getUpgradePoint() >= 0 && movementSpeedPoint > 0)
            {
                Node* movementSpeedValue = this->upgradeHeroLayer->getChildByName("upgradeMovementSpeedValue");
                switch (type)
                {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                    movementSpeedPoint -= 1;
                    ((Label*)movementSpeedValue)->setString(std::to_string(movementSpeedPoint));
                    heroManager->getHero()->setUpgradePoint(heroManager->getHero()->getUpgradePoint() + 1);
                    break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:

                    break;
                default:
                    break;
                }
            }
        });

    this->applyBtn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
        {
            Node* healthValue = this->upgradeHeroLayer->getChildByName("upgradeHealthValue");
            Node* shieldValue = this->upgradeHeroLayer->getChildByName("upgradeShieldValue");
            Node* damageValue = this->upgradeHeroLayer->getChildByName("upgradeDamageValue");
            Node* attackSpeedValue = this->upgradeHeroLayer->getChildByName("upgradeAttackSpeedValue");
            Node* movementSpeedValue = this->upgradeHeroLayer->getChildByName("upgradeMovementSpeedValue");
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                if(healthPoint > 0)
                {
                    heroManager->getHero()->setMaxHealth(healthPoint * 2.0f);
                    healthPoint = 0;
                    ((Label*)healthValue)->setString(std::to_string(healthPoint));
                }
                if (shieldPoint > 0)
                {
                    heroManager->getHero()->setMaxShield(shieldPoint * 0.25f);
                    shieldPoint = 0;
                    ((Label*)shieldValue)->setString(std::to_string(shieldPoint));
                }
                if (damagePoint > 0)
                {
                    heroManager->getHero()->setMaxDamage(damagePoint * 0.5f);
                    damagePoint = 0;
                    ((Label*)damageValue)->setString(std::to_string(damagePoint));
                }
                if (attackSpeedPoint > 0)
                {
                    heroManager->getHero()->setMaxAttackSpeed(attackSpeedPoint * 0.05f);
                    attackSpeedPoint = 0;
                    ((Label*)attackSpeedValue)->setString(std::to_string(attackSpeedPoint));
                }
                if (movementSpeedPoint > 0)
                {
                    heroManager->getHero()->setMaxMovementSpeed(movementSpeedPoint * 0.15f);
                    movementSpeedPoint = 0;
                    ((Label*)movementSpeedValue)->setString(std::to_string(movementSpeedPoint));
                }
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:

                break;
            default:
                break;
            }
        });
}

void GameScene::updateShowUpgradeHero()
{
    std::string hp = std::to_string(heroManager->getHero()->getMaxHealth());
    std::string sh = std::to_string(heroManager->getHero()->getMaxShield());
    std::string atk = std::to_string(heroManager->getHero()->getMaxDamage());
    std::string asp = std::to_string(heroManager->getHero()->getMaxAttackSpeed());
    std::string msp = std::to_string(heroManager->getHero()->getMaxMovementSpeed());
    std::string point = std::to_string(heroManager->getHero()->getUpgradePoint());

    hp = hp.substr(0, hp.find(".") + 3);
    sh = sh.substr(0, sh.find(".") + 3);
    atk = atk.substr(0, atk.find(".") + 3);
    asp = asp.substr(0, asp.find(".") + 3);
    msp = msp.substr(0, msp.find(".") + 3);

    Node* hpValue = this->upgradeHeroLayer->getChildByName("hpValue");
    ((Label*)hpValue)->setString(hp);
    Node* shValue = this->upgradeHeroLayer->getChildByName("shValue");
    ((Label*)shValue)->setString(sh);
    Node* atkValue = this->upgradeHeroLayer->getChildByName("atkValue");
    ((Label*)atkValue)->setString(atk);
    Node* aspValue = this->upgradeHeroLayer->getChildByName("aspValue");
    ((Label*)aspValue)->setString(asp);
    Node* mspValue = this->upgradeHeroLayer->getChildByName("mspValue");
    ((Label*)mspValue)->setString(msp);
    Node* upgradePointValue = this->upgradeHeroLayer->getChildByName("upgradePointValue");
    ((Label*)upgradePointValue)->setString(point);
}

void GameScene::followHero()
{
    auto camera = getDefaultCamera();
    Vec2 targetPos = this->heroManager->getHero()->getPosition();
    auto visibleSize = Singleton<GameManager>::getIntsance()->getVisibleSize();
    targetPos.x = clampf(targetPos.x, (visibleSize.width - (BOUNDING_BOX.width - visibleSize.width)) / 2, (visibleSize.width + (BOUNDING_BOX.width - visibleSize.width)) / 2);
    targetPos.y = clampf(targetPos.y, (visibleSize.height - (BOUNDING_BOX.height - visibleSize.height)) / 2, (visibleSize.height + (BOUNDING_BOX.height - visibleSize.height)) / 2);
    Vec2 currentPos = camera->getPosition();
    currentPos = currentPos.lerp(targetPos, 0.1);
    camera->setPosition(currentPos);
}


Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact& _contact)
{
    auto heroJob = heroManager->getHeroJob();
    if (m_contactStarted)
    {
        return true;
    }
    if ((_contact.getShapeA()->getCategoryBitmask() & _contact.getShapeB()->getCollisionBitmask()) <= 0 ||
        (_contact.getShapeB()->getCategoryBitmask() & _contact.getShapeA()->getCollisionBitmask()) <= 0)
    {
        return false;
    }

    auto nodeA = _contact.getShapeA()->getBody()->getNode();
    auto nodeB = _contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        int tagA = nodeA->getTag();
        int tagB = nodeB->getTag();
        if ((tagA == PLAYER_ATTACK_TAG && tagB == ENEMY_TAG)
            || (tagB == PLAYER_ATTACK_TAG && tagA == ENEMY_TAG))
        {
            if (heroJob == HeroJob::Knight)
            {
                SwordSlash* attack = (SwordSlash*)(tagA == PLAYER_ATTACK_TAG ? nodeA : nodeB);
                attack->getPhysicsBody()->setRotationEnable(false);
                Enemy* enemy = (Enemy*)(tagA == ENEMY_TAG ? nodeA : nodeB);
                enemy->takeDamage(attack->getDamage());
            }
            else
            {
                BowShot* attack = (BowShot*)(tagA == PLAYER_ATTACK_TAG ? nodeA : nodeB);
                attack->getPhysicsBody()->setRotationEnable(false);
                attack->setLifeTime(0.0f);
                Enemy* enemy = (Enemy*)(tagA == ENEMY_TAG ? nodeA : nodeB);
                enemy->takeDamage(attack->getDamage());
            }
        }
    }
    m_contactStarted = true;
    return true;
}

void GameScene::onContactSeparate(cocos2d::PhysicsContact& _contact)
{
    auto nodeA = _contact.getShapeA()->getBody()->getNode();
    auto nodeB = _contact.getShapeB()->getBody()->getNode();

    if (nodeA && nodeB)
    {
        //nodeA->setColor(Color3B::WHITE);
        //nodeB->setColor(Color3B::WHITE);
        m_contactStarted = false;
        int tagA = nodeA->getTag();
        int tagB = nodeB->getTag();
    }
}

void GameScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_TAB:
        this->upgradeHeroLayer->setVisible(!this->upgradeHeroLayer->isVisible());
        break;
    case EventKeyboard::KeyCode::KEY_ESCAPE:

        break;
    default:
        break;
    }
}

void GameScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_TAB:

        break;
    case EventKeyboard::KeyCode::KEY_ESCAPE:

        break;
    default:
        break;
    }
}

void GameScene::onMouseMove(cocos2d::Event* event)
{
    EventMouse* e = (EventMouse*)event;
    this->lastMousePositon = e->getLocationInView();

}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::initWithPhysics() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    contactListener->onContactSeparate = CC_CALLBACK_1(GameScene::onContactSeparate, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

    auto keyBoardListener = EventListenerKeyboard::create();
    keyBoardListener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    keyBoardListener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListener, this);

    auto mouseListener = EventListenerMouse::create();
    mouseListener->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);

    this->initCameraUI();
    this->initPlayerInfo();
    this->initShowUpgradeHero();
    this->initTileMap((Vec2)visibleSize);

    Singleton<GameManager>::getIntsance()->addScene(this);
    Singleton<GameManager>::getIntsance()->addVisibleSize(visibleSize);

    this->heroManager->setScene(this);
    this->heroManager->spawnHero(this->heroManager->getHeroJob(), Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto enemy = new Skeleton();
    enemy->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100));
    this->addChild(enemy);

    //this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    //this->getPhysicsWorld()->setGravity(Vec2(0,-98));
    scheduleUpdate();
    return true;
}

void GameScene::update(float dt)
{
    this->followHero();
    heroManager->update(dt);
    this->updatePlayerInfo(dt);
    this->updateShowUpgradeHero();
}
