#ifndef ENEMY_SHIP_HPP
# define ENEMY_SHIP_HPP

#include "Ship.hpp"
#include <string>

class EnemyShip : public Ship
{
private:
    std::string name1 = "u-u";
    std::string name2 = "|o|";
    std::string name3 = "v v";
public:
    EnemyShip();
    ~EnemyShip();

    void    moveLeft(void);
    void    moveRight(void);
    void    dies(void);
};


#endif