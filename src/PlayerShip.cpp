#include "PlayerShip.hpp"

PlayerShip::PlayerShip(void)
{
    this->health = 100;
    this->name = "Toto";
}

PlayerShip::PlayerShip(const PlayerShip &s) : Ship(s)
{
    this->health = s.health;
    this->name = s.name; // XXX a corriger
}

PlayerShip &PlayerShip::operator=(const PlayerShip &p) 
{
    if (this != &p) {
        this->health = p.health;
        this->name = p.name;
    } // XXX a corriger
    return *this;
}

void PlayerShip::dies() 
{
    
}
