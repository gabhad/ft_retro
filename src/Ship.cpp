#include "Ship.hpp"

Ship::Ship()
{
}

Ship::Ship(Ship &s)
{
    this->health = s.health; // XXX a corriger
}

Ship &Ship::operator=(const Ship &p)
{
    this->health = p.health; // XXX a corriger
    return *this; 
}

Ship::~Ship()
{
}

void    Ship::changesWeapon(Weapon newWeap) 
{
    this->weap = newWeap;
}

void    Ship::shootsMissile(void)
{

}

void    Ship::getsDamage(int dmg) 
{
    this->health -= dmg;
    if (this->health <= 0)
        dies();
}

