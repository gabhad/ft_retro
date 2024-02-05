//unchanged

#ifndef ENEMY_SHIP_HPP
# define ENEMY_SHIP_HPP

#include "Ship.hpp"
#include <string>

class EnemyShip : public IShip {
private:
    std::string name1 = "u-u";
    std::string name2 = "|o|";
    std::string name3 = "v v";

public:
    EnemyShip();
    EnemyShip(const EnemyShip &);
    EnemyShip &operator=(const EnemyShip &);

    ~EnemyShip();

    void    moveLeft(void);
    void    moveRight(void);
    void    dies(void);
};

#endif  // ENEMY_SHIP_HPP