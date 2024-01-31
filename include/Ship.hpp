#ifndef SHIP_H
    #define SHIP_H

#include "Weapon.hpp"

class Ship
{
protected:
    int health;
    Weapon weap;

public:
    Ship();
    Ship(const Ship &s);
    Ship &operator=(const Ship &p);

    ~Ship();

    void            changesWeapon(Weapon newWeap);
    void            shootsMissile(void);
    void            getsDamage(int dmg);
    virtual void    dies(void) = 0;
};


#endif