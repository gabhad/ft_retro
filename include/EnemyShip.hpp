#ifndef ENEMY_SHIP_HPP
# define ENEMY_SHIP_HPP

#include <string>
#include <ctime>

#include "Ship.hpp"

class EnemyShip : public IShip{
private:
    static int  count;
    static int  numDeath;
    time_t      lastShot;

    void    dies(void);

public:
    EnemyShip();
    EnemyShip(const EnemyShip &);
    EnemyShip &operator=(const EnemyShip &);

    ~EnemyShip();

    bool        isDead;

    // Getters
    int     getPositionX(void);
    int     getPositionY(void);
    int     getHealth(void);
    int     getNumDeath(void);
    
    void    printShip (WINDOW *win);

    // Actions
    void    moveDownRight(void);
    void    moveDownLeft(void);
    int     shootsMissile(void);
    void    getsDamage(int dmg);
   // void    dies(void);

    void    resetCount(void);
    void    resetDeath(void);

};

#endif  // ENEMY_SHIP_HPP