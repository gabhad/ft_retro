#ifndef SHIP_HPP
# define SHIP_HPP

#include "Weapon.hpp"
#include "ncurses.h"

class IShip {
protected:
    int             health;
    Weapon          weap;

public:
    IShip();
    IShip(const IShip &);
    IShip &operator=(const IShip &);

    ~IShip();

    void            changesWeapon(Weapon newWeap);
    void            shootsMissile(void);
    void            getsDamage(int dmg);
    virtual void    moveLeft(void) = 0;
    virtual void    moveRight(void) = 0;
    virtual void    dies(void) = 0;
    virtual void    printShip(WINDOW *win, int position) = 0;

};

#endif  // SHIP_HPP