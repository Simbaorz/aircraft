
#include "Config.h"

USING_NS_CC;

/**
 * 初始化为空指针
 */
Config* Config::config = nullptr;

/**
 * 单例类
 */
Config* Config::getInstance()
{
    if(config)
    {
        return config;
    }
    log("first config");
    config = new Config();
    
    return config;
}