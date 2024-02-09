#ifndef ENEMY_SHIP_HPP
# define ENEMY_SHIP_HPP

#include <string>

#include "Ship.hpp"

class EnemyShip : public IShip{
private:
    bool    isDead;
public:
    EnemyShip();
    EnemyShip(const EnemyShip &);
    EnemyShip &operator=(const EnemyShip &);

    ~EnemyShip();

    // Getters
    int     getPositionX(void);
    int     getPositionY(void);
    int     getHealth(void);
    
    void    printShip (WINDOW *win, const EnemyShip &);

    // Actions
    void    shootsMissile(void);
    void    moveLeft(void);
    void    moveRight(void);
    void    moveDown(void);
    void    getsDamage(int dmg);
    void    dies(void);

};

#endif  // ENEMY_SHIP_HPP