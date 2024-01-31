#ifndef PLAYER_SHIP_H
    #define PLAYER_SHIP_H

#include <string>
#include "Weapon.hpp"
#include "Ship.hpp"

class PlayerShip : public Ship {
    private:
        std::string name;

    public:
        PlayerShip(void);
        PlayerShip(const PlayerShip &p);
        PlayerShip &operator=(const PlayerShip &p);

        ~PlayerShip();

        void    dies();
};

#endif // PLAYER_SHIP_H