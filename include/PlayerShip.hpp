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
    int         positionX;
    int         positionY;
    
public:
    PlayerShip();
    PlayerShip(const PlayerShip &);
    PlayerShip &operator=(const PlayerShip &);

    ~PlayerShip();

    // Getters
    int     getPositionX(void);
    int     getPositionY(void);
    int     getHealth(void);
    
    void    printShip (WINDOW *win, const PlayerShip &);
    
    // Inheritance functions
    void    shootsMissile(void);
    void    moveLeft(void);
    void    moveRight(void);
    void    moveUp(void);
    void    moveDown(void);

    void    dies(void);

};


#endif  // PLAYER_SHIP_HPP