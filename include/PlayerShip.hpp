#ifndef PLAYER_SHIP_H
    #define PLAYER_SHIP_H

#include <string>
#include "Weapon.hpp"
#include "Ship.hpp"

class PlayerShip : public Ship {
    private:
        std::string name;
        int         health;
        Weapon      weap;

    public:
        PlayerShip(void);
        PlayerShip(const PlayerShip &p);
        PlayerShip &operator=(const PlayerShip &p);

        ~PlayerShip();

        void    shoot(void);
        void    gets_damage(int dmg);
};

#endif