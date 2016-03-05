
#include "GameLayer.h"
#include "Constant.h"

USING_NS_CC;
GameLayer::GameLayer() : bg1(nullptr), bg2(nullptr), winSize(Director::getInstance()->getWinSize())
{
    
}

GameLayer::~GameLayer()
{
    bg1->release();
    bg2->release();
}

Scene* GameLayer::createScene()
{
    Scene* scene = Scene::create();
    auto layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameLayer::init()
{
    log("init");
    bool bRet = false;
    
    do{
        if(!Layer::init())
        {
            return bRet;
        }
        
        bRet = true;
    }while(0);
    return bRet;
}

void GameLayer::onEnter()
{
    Layer::onEnter();

    auto bg1 = Sprite::create(BG1);
    auto bg2 = Sprite::create(BG2);
    this->bg1 = bg1;
    this->bg2 = bg2;
    bg1->retain();
    bg2->retain();
    bg1->setPosition(Point::ZERO);
    bg1->setAnchorPoint(Point::ZERO);
    bg1->getTexture()->setAliasTexParameters();
    bg2->setPosition(Point(0, winSize.height));
    bg2->setAnchorPoint(Point::ZERO);
    bg2->getTexture()->setAliasTexParameters();
    addChild(bg1, 0);
    addChild(bg2, 0);
    schedule(schedule_selector(GameLayer::update));
}

void GameLayer::onExit()
{
    Layer::onExit();
}

void GameLayer::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
}

void GameLayer::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
}


void GameLayer::scrollBG()
{
    Point p1 = bg1->getPosition();
    Point p2 = bg2->getPosition();
    p1.y -= 5.0;
    p2.y -= 5.0;

    if(p1.y <= -bg1->getContentSize().height)
    {
        p1.y = bg1->getContentSize().height;
    }
    
    if(p2.y <= -bg2->getContentSize().height)
    {
        p2.y = bg2->getContentSize().height;
    }
    
    bg1->setPosition(p1);
    bg2->setPosition(p2);
}

void GameLayer::update(float dt)
{
    scrollBG();
}


