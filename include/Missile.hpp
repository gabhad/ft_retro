#ifndef MISSILE_HPP
# define MISSILE_HPP

#include <string>
#include "Ship.hpp"

class Missile {
private:
    int         damage;
    std::string direction;
public:
    Missile(int, std::string);
    Missile(const Missile &);
    Missile &operator=(const Missile &);

    ~Missile();

    void    dealsDamage(IShip *ship);
};

#endif  // MISSILE_HPP