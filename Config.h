
#ifndef __airfight__Config__
#define __airfight__Config__

#include "cocos2d.h"

class Config
{
private:
    //背景音乐
    bool _isBGMusicOn;
    
    //背景音乐音量
    float _BGMusicVolume;
    
    //特效
    bool _isEffectOn;
    
    //特效音量
    float _effectVolume;
    
    Config() : _isBGMusicOn(true), _BGMusicVolume(0.5), _isEffectOn(true), _effectVolume(0.5) {}
    
    
public:
    //单线程单例类
    static Config* config;
    
    static Config* getInstance();
    
    inline void setBGMusicState(bool state)
    {
        _isBGMusicOn = state;
    }
    
    inline bool getBGMusicState()
    {
        return _isBGMusicOn;
    }
    
    inline void setBGMusicVolume(float volume)
    {
        _BGMusicVolume = volume;
    }
    
    inline float getBGMusicVolume()
    {
        return _BGMusicVolume;
    }
    
    inline void setEffectState(bool state)
    {
        _isEffectOn = state;
    }
    
    inline bool getEffectState()
    {
        return _isEffectOn;
    }
    
    inline void setEffectVolume(float volume)
    {
        _effectVolume = volume;
    }
    
    inline float getEffectVolume()
    {
        return _effectVolume;
    }
    
    ~Config()
    {
        cocos2d::log("Config destroy");
    }
};

#endif /* defined(__airfight__Config__) */
