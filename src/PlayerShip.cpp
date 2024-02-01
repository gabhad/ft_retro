#include "PlayerShip.hpp"

PlayerShip::PlayerShip(void)
{
    this->health = 10;
}

PlayerShip::PlayerShip(const PlayerShip &s) : Ship(s)
{
    this->health = s.health;
}

PlayerShip &PlayerShip::operator=(const PlayerShip &p) 
{
    if (this != &p) {
        this->health = p.health;
    } // XXX a corriger
    return *this;
}

void    PlayerShip::moveLeft(void) {}
void    PlayerShip::moveRight(void) {}

void PlayerShip::dies(void) 
{
    
}
