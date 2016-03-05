
#ifndef __airfight__GameMenuLayer__
#define __airfight__GameMenuLayer__

#include "cocos2d.h"
#include "Config.h"
#include "SimpleAudioEngine.h"

class GameMenuLayer : public cocos2d::Layer
{
private:
    const cocos2d::Size& winSize;
    //飞船
    cocos2d::Sprite* mpShip;
    
public:
    GameMenuLayer();
    
    ~GameMenuLayer();
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(GameMenuLayer);
    
    void flareEffect(const cocos2d::Ref* pSender);
    
    void setting(const cocos2d::Ref* pSender);
    
    void about(const cocos2d::Ref* pSender);
    
    virtual void update(float dt);
    
    inline void playButtonEffect()
    {
        if(Config::getInstance()->getEffectState())
        {
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(Config::getInstance()->getEffectVolume());
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("buttonEffet.mp3");
        }
    }
    
};

#endif /* defined(__airfight__GameMenuLayer__) */
