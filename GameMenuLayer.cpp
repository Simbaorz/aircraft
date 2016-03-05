/**
 * @author simba
 * @date 2015-5-13
 */

#include "GameMenuLayer.h"

//ui头文件
//#include "ui/CocosGUI.h"

#include "Config.h"
#include "Constant.h"
#include "SimpleAudioEngine.h"
#include "GameLayer.h"
#include "TiledTestLayer.h"

using namespace CocosDenshion;

USING_NS_CC;
//命名空间ui定义在cocos2d内部
//using namespace ui;

/**
 * 初始化winSize,因为Director的生命周期比当前对象要长
 */
GameMenuLayer::GameMenuLayer() : winSize(Director::getInstance()->getWinSize()), mpShip(nullptr)
{
    
}

GameMenuLayer::~GameMenuLayer()
{
    mpShip->release();
}

Scene* GameMenuLayer::createScene()
{
    Scene* pRet = nullptr;
    do{
        auto layer = GameMenuLayer::create();
        
        pRet = Scene::create();
        
        pRet->addChild(layer);
    }while(0);
    return pRet;
}

bool GameMenuLayer::init()
{
    bool bRet = false;
    do{
        if(!Layer::init())
        {
            return bRet;
        }
        //添加背景图片
        auto loading = Sprite::create(LOADING);
        loading->setAnchorPoint(Point::ZERO);
        loading->setPosition(Point::ZERO);
        addChild(loading,0, 1);
        
        //添加logo
        auto logo = Sprite::create(LOGO);
        logo->setAnchorPoint(Point(0.5 ,1));
        logo->setPosition(Point(winSize.width/2, winSize.height - 50));
        //zOrder, tag
        addChild(logo, 0, 2);
        
        //newGameItem
        auto newGameNormal = Sprite::create(MENU, Rect(0, 0, 126, 33));
        auto newGameSelected = Sprite::create(MENU, Rect(0, 33, 126, 33));
        auto newGameDisable = Sprite::create(MENU, Rect(0, 33*2, 126, 33));
        auto newGameItem = MenuItemSprite::create(newGameNormal, newGameSelected, newGameDisable, CC_CALLBACK_1(GameMenuLayer::flareEffect, this));
        //settingItem
        auto settingItemNormal = Sprite::create(MENU, Rect(126, 0, 126, 33));
        auto settingItemSelected = Sprite::create(MENU, Rect(126, 33, 126, 33));
        auto settingItemDisable = Sprite::create(MENU, Rect(126, 33*2, 126, 33));
        auto settingItem = MenuItemSprite::create(settingItemNormal, settingItemSelected, settingItemDisable, CC_CALLBACK_1(GameMenuLayer::setting, this));
        //aboutItem
        auto aboutItemNormal = Sprite::create(MENU, Rect(252, 0, 126, 33));
        auto aboutItemSelected = Sprite::create(MENU, Rect(252, 33, 126, 33));
        auto aboutItemDisable = Sprite::create(MENU, Rect(252, 33*2, 126, 33));
        auto aboutItem = MenuItemSprite::create(aboutItemNormal, aboutItemSelected, aboutItemDisable, CC_CALLBACK_1(GameMenuLayer::about, this));
        //添加Menu
        auto menu = Menu::create(newGameItem, settingItem, aboutItem, NULL);
        menu->alignItemsVerticallyWithPadding(20);
        menu->setPosition(Point(winSize.width / 2, winSize.height / 2 - 80));
        this->addChild(menu, 1, 3);
        
        schedule(schedule_selector(GameMenuLayer::update), 0.1);
        
        auto textureCache = Director::getInstance()->getTextureCache()->addImage(SHIP);
        
        mpShip = Sprite::createWithTexture(textureCache, Rect(0, 45, 60, 38));
        mpShip->retain();
        
        //log("%d", mpShip->getReferenceCount());
        Point p = Point(CCRANDOM_0_1() * winSize.width, 10);
        mpShip->setPosition(p);
        mpShip->runAction(MoveBy::create(floor(CCRANDOM_0_1() * 5), Point(CCRANDOM_0_1() * winSize.width, p.y + winSize.height + 100)));
        addChild(mpShip, 0, 4);
        bRet = true;
        
        if(Config::getInstance()->getBGMusicState())
        {
            SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(Config::getInstance()->getBGMusicVolume());
            SimpleAudioEngine::getInstance()->playBackgroundMusic(BG_MUSIC, true);
        }
    }while(0);
    
    return bRet;
}

/**
 * new game
 */
void GameMenuLayer::flareEffect(const Ref* pSender)
{
    playButtonEffect();

    auto  transitionFade = TransitionFade::create(2, GameLayer::createScene(), Color3B::BLACK);
    Director::getInstance()->replaceScene(transitionFade);
}

/**
 * setting scene
 */
void GameMenuLayer::setting(const cocos2d::Ref* pSender)
{
    playButtonEffect();
    auto  transitionFade = TransitionFade::create(2, TiledTestLayer::createScene(), Color3B::BLACK);
    Director::getInstance()->replaceScene(transitionFade);
}

/**
 * about scene
 */
void GameMenuLayer::about(const cocos2d::Ref* pSender)
{
    playButtonEffect();
}

/**
 * update
 */
void GameMenuLayer::update(float time)
{
    if(mpShip->getPosition().y > winSize.height)
    {
        Point pos = Point(CCRANDOM_0_1() * winSize.width, 10);
        mpShip->setPosition(pos);
        mpShip->runAction(MoveBy::create(floor(5 * CCRANDOM_0_1()), Point(CCRANDOM_0_1() * winSize.width, pos.y + winSize.height)));
    }
}




