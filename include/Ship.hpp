#ifndef SHIP_H
    #define SHIP_H

#include "Weapon.hpp"

class Ship
{
protected:
    int     health;
    Weapon  weap;
    int     position;

public:
    Ship();
    Ship(const Ship &s);
    Ship &operator=(const Ship &p);

    ~Ship();

    void            changesWeapon(Weapon newWeap);
    void            shootsMissile(void);
    void            getsDamage(int dmg);
    void            moveLeft(void);
    void            moveRight(void);
    virtual void    dies(void) = 0;
};


#endif