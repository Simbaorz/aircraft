
#ifndef __airfight__GameLayer__
#define __airfight__GameLayer__

#include "cocos2d.h"

class GameLayer : public cocos2d::Layer
{
private:
    cocos2d::Sprite* bg1;
    cocos2d::Sprite* bg2;
    const cocos2d::Size& winSize;
public:
    GameLayer();
    
    ~GameLayer();
    
    virtual bool init();
    
    CREATE_FUNC(GameLayer);
    
    static cocos2d::Scene* createScene();
    
    virtual void onEnter() override;
    
    virtual void onExit() override;
    
    virtual void onEnterTransitionDidFinish() override;
    
    virtual void onExitTransitionDidStart() override;
    
    virtual void update(float dt);
    
    void scrollBG();
    

};

#endif
