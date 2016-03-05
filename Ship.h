/**
 * 遵守驼峰命名法
 */


#ifndef __airfight__Ship__
#define __airfight__Ship__

#include "cocos2d.h"
/**
 *  武器
 *
 */
class Weapon
{
private:
    unsigned attackValue;
    unsigned attackSpeed;
public:
};

/**
 * 飞船
 *
 */
class Ship : public cocos2d::Sprite
{
private:
    unsigned int hp;
    unsigned int mp;
    unsigned int grade;
    
    Weapon weapon;
    
public:
    inline unsigned int getHp()
    {
        return hp;
    }
    
    inline void setHp(unsigned int hp)
    {
        this->hp = hp;
    }
    
    inline void setMp(unsigned int mp)
    {
        this->mp = mp;
    }
    
    inline unsigned int getMp()
    {
        return mp;
    }
    
    void attack();
    
    inline void updateGrade()
    {
        ++(this->update)
    }
    
    inline unsigned int getGrade()
    {
        return grade;
    }
    
    inline Weapon& getWeapon()
    {
        return weapon;
    }
    
    inline void setWeapon(const Weapon& weapon)
    {
        this.weapon = weapon;
    }
};

#endif /* defined(__airfight__Ship__) */
