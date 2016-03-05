/**
 *
 * 测试瓦片地图
 */

#ifndef __airfight__TiledTestLayer__
#define __airfight__TiledTestLayer__

#include "cocos2d.h"

class TiledTestLayer : public cocos2d::Layer
{
private:
    cocos2d::TMXTiledMap* map;
    cocos2d::Sprite* player;
    float screenWidth;
    float screenHeight;
public:
    TiledTestLayer();
    
    ~TiledTestLayer();
    
    CREATE_FUNC(TiledTestLayer);
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    virtual void onEnter();
    
    void setViewPointCenter(cocos2d::Point position);
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    void centerPlayer(cocos2d::Point clickPoint);
};

#endif /* defined(__airfight__TiledTestLayer__) */
