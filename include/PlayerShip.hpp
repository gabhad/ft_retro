#ifndef PLAYER_SHIP_HPP
# define PLAYER_SHIP_HPP

#include <string>
#include "Weapon.hpp"
#include "Ship.hpp"

class PlayerShip : public IShip {
private:
    std::string name1 = "^ /\\ ^";
    std::string name2 = "| ll |";
    std::string name3 = "vv";
    int         position;
public:
    PlayerShip();
    PlayerShip(const PlayerShip &);
    PlayerShip &operator=(const PlayerShip &);

    ~PlayerShip();

    void    moveLeft(void);
    void    moveRight(void);
    void    dies(void);
    void    printShip (WINDOW *win, int position);
};


#endif  // PLAYER_SHIP_HPP