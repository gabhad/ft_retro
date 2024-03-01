#ifndef SHIP_HPP
# define SHIP_HPP

#include "Weapon.hpp"
#include "ncurses.h"


class IShip {
protected:
    std::string name1;
    std::string name2;
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
    virtual int     shootsMissile(void) = 0;
    virtual void    dies(void) = 0;
    virtual void    getsDamage(int dmg) = 0;

};

#endif  // SHIP_HPP