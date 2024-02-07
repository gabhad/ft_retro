#ifndef MISSILE_HPP
# define MISSILE_HPP

#include <string>

#include "Ship.hpp"
#include "GameEntity.hpp"

class Missile {
private:
    int         damage;
    std::string direction;
    int         x;
    int         y;
public:
    Missile(int, std::string, int, int);
    Missile(const Missile &);
    Missile &operator=(const Missile &);

    ~Missile();

    void    dealsDamage(IShip *ship);
    void    printMissile(Missile &, GameEntity &G);
    void    updateMissiles(Missile &);
};

#endif  // MISSILE_HPP