

#include "TiledTestLayer.h"
#include "Constant.h"
USING_NS_CC;
TiledTestLayer::TiledTestLayer() : map(nullptr), player(nullptr),screenWidth(Director::getInstance()->getWinSize().width), screenHeight(Director::getInstance()->getWinSize().height) {}


TiledTestLayer::~TiledTestLayer()
{
    map->release();
    player->release();
}

bool TiledTestLayer::init()
{
    auto bRet = false;
    do{
        if(!Layer::init())
        {
            return bRet;
        }
        
        //code
        bRet = true;
    }while (0);
    return bRet;
}

/**
 * 将player作为view的中心
 */
void TiledTestLayer::centerPlayer(Point clickPoint)
{
    log("centerPlayer");
    Point playerPosition = player->getPosition();
    Point mapPosition = map->getPosition();
    Size mapSize = map->getContentSize();
    Size playerSize = player->getContentSize();
    
    
}

void TiledTestLayer::onEnter()
{
    Layer::onEnter();
    Director::getInstance()->getTextureCache()->addImage("charlet.png");
    map = TMXTiledMap::create("test.tmx");
    map->retain();
    player = Sprite::create("player.png");
    player->retain();
    //player->setPosition(Point::ZERO);
    player->setAnchorPoint(Point::ZERO);
    player->setFlippedX(true);
    map->setAnchorPoint(Point::ZERO);
    map->setPosition(Point::ZERO);
    
    auto objects = map->getObjectGroup("ObjectLayer");
    ValueMap valueMap = objects->getObject("player");
    
    int x = valueMap.at("x").asInt();
    int y = valueMap.at("y").asInt();
    player->setPosition(x, y);
    addChild(map, MAP_Z_ORDER, MAP_TAG);
    addChild(player, PLAYER_Z_ORDER, PLAYER_TAG);
    
    
    //
    centerPlayer(Point::ZERO);
    //添加监听器
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(TiledTestLayer::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(TiledTestLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

Scene* TiledTestLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = TiledTestLayer::create();
    scene->addChild(layer);
    return scene;
}

void TiledTestLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    centerPlayer(touch->getLocation());
}

bool TiledTestLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}