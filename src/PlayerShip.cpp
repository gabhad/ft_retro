#include "PlayerShip.hpp"

PlayerShip::PlayerShip(void) {}
PlayerShip::PlayerShip(const PlayerShip &s)
{
    this->health = s.health; // XXX a corriger
}

PlayerShip &PlayerShip::operator=(const PlayerShip &p) 
{
    this->health = p.health; // XXX a corriger
    return *this;
}

void PlayerShip::dies() {}
