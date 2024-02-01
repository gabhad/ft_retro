#ifndef PLAYER_SHIP_HPP
# define PLAYER_SHIP_HPP

#include <string>
#include "Weapon.hpp"
#include "Ship.hpp"

class PlayerShip : public Ship {
    private:
        std::string name1 = "^ /\\ ^";
        std::string name2 = "| ll |";
        std::string name3 = "vv";

    public:
        PlayerShip(void);
        PlayerShip(const PlayerShip &p);
        PlayerShip &operator=(const PlayerShip &p);

        ~PlayerShip();

        void    moveLeft(void);
        void    moveRight(void);
        void    dies(void);
};

#endif // PLAYER_SHIP_H