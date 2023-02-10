#include "LoadingScene.h"
#include "IntroScene.h"
#include <cocos/ui/UILoadingBar.h>
USING_NS_CC;

Scene* LoadingScene::createScene()
{
    return LoadingScene::create();
}

void LoadingScene::initLoading(Vec2 position)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(LOADING_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(KNIGHT_M_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(KNIGHT_M_BODY_PLIST);
    resourceList.push_back(KNIGHT_M_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ELF_M_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(ELF_M_BODY_PLIST);
    resourceList.push_back(ELF_M_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(LIZARD_M_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(LIZARD_M_BODY_PLIST);
    resourceList.push_back(LIZARD_M_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(WIZARD_F_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(WIZARD_F_BODY_PLIST);
    resourceList.push_back(WIZARD_F_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(WEAPON_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(WEAPON_BODY_PLIST);
    resourceList.push_back(WEAPON_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(SWORD_SLASH_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(SWORD_SLASH_BODY);
    resourceList.push_back(SWORD_SLASH_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(BOW_SHOT_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(BOW_SHOT_BODY);
    resourceList.push_back(BOW_SHOT_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(SKELETON_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(SKELETON_BODY_PLIST);
    resourceList.push_back(SKELETON_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(SKELETON_SLASH_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(SKELETON_SLASH_BODY);
    resourceList.push_back(SKELETON_SLASH);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ZOMBIEBOSS_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(ZOMBIEBOSS_BODY_PLIST);
    resourceList.push_back(ZOMBIEBOSS_PLIST);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ZOMBIEBOSS_PUNCH_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(ZOMBIEBOSS_PUNCH_BODY);
    resourceList.push_back(ZOMBIEBOSS_PUNCH);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ZOMBIEBOSS_GROUND_PLIST);
    PhysicsShapeCache::getInstance()->addShapesWithFile(ZOMBIEBOSS_GROUND_BODY);
    resourceList.push_back(ZOMBIEBOSS_GROUND);

    auto loadingbar_bg = Sprite::create("ui/LoadingBarBackground.png");
    loadingbar_bg->setPosition(Vec2(position.x * 0.5, position.y * 0.4));
    this->addChild(loadingbar_bg);

    auto loadingbar = ui::LoadingBar::create("ui/LoadingBar.png");
    loadingbar->setPosition(loadingbar_bg->getPosition());
    loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);
    this->addChild(loadingbar);
    schedule([=](float dt) {
        float percent = loadingbar->getPercent();
        if (resourceLoaded < resourceList.size() &&
            SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(resourceList.at(resourceLoaded).c_str()))
        {
            percent += (1.0f/ (float)resourceList.size())*100.0f;
            loadingbar->setPercent(percent);
        }
        if (percent > 100)
        {
            loadingbar->setPercent(100);
            unschedule("updateLoadingBar");
            auto introScene = IntroScene::createScene();
            Director::getInstance()->replaceScene(TransitionCrossFade::create(1.0, introScene));
        }
        }, fixedtimestep, "updateLoadingBar");
}

void LoadingScene::initLoadingLabel(Vec2 position)
{
    if (SpriteFrameCache::getInstance()->isSpriteFramesWithFileLoaded(LOADING_PLIST))
    {
        Entity* loadingText = new Entity();
        loadingText->setPosition(Vec2(position.x/2 - loadingText->getContentSize().width/2
                                    , position.y / 2 - loadingText->getContentSize().height/2));
        loadingText->setSpriteFrame(LOADING,0,false);
        loadingText->setAnimation(REPEAT::FOREVER,LOADING,0,3,fixedtimestep);
        this->addChild(loadingText);
    }
}


// on "init" you need to initialize your instance
bool LoadingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->initLoading((Vec2)visibleSize);
    this->initLoadingLabel((Vec2)visibleSize);

    return true;
}

