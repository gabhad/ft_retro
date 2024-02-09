#ifndef SHIP_HPP
# define SHIP_HPP

#include "Weapon.hpp"
#include "ncurses.h"

class IShip {
protected:
    std::string name1;
    std::string name2;
    std::string name3;
    int         positionX;
    int         positionY;
    int         health;
    Weapon      *weap;

public:
    IShip();
    IShip(const IShip &);
    IShip &operator=(const IShip &);

    virtual ~IShip();

    
    // Getters
    virtual int     getPositionX(void) = 0;
    virtual int     getPositionY(void) = 0;
    virtual int     getHealth(void) = 0;

    // Actions
    virtual void    shootsMissile(void) = 0;
    virtual void    moveLeft(void) = 0;
    virtual void    moveRight(void) = 0;
    virtual void    moveDown(void) = 0;
    virtual void    dies(void) = 0;
    virtual void    getsDamage(int dmg) = 0;

};

#endif  // SHIP_HPP