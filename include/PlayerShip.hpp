#ifndef PLAYER_SHIP_HPP
# define PLAYER_SHIP_HPP

#include <string>
#include "Weapon.hpp"
#include "Ship.hpp"

class PlayerShip : public IShip {
private:
    
public:
    PlayerShip();
    PlayerShip(const PlayerShip &);
    PlayerShip &operator=(const PlayerShip &);

    ~PlayerShip();

    void            changesWeapon(Weapon *newWeap);

    // Getters
    int     getPositionX(void);
    int     getPositionY(void);
    int     getHealth(void);
        
    // Actions
    void    shootsMissile(void);
    void    moveLeft(void);
    void    moveRight(void);
    void    moveUp(void);
    void    moveDown(void);
    void    getsDamage(int dmg);
    void    dies(void);

    // Display
    void    printShip (WINDOW *win, const PlayerShip &);


};


#endif  // PLAYER_SHIP_HPP