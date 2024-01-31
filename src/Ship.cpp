#include "Ship.hpp"

Ship::Ship()
{
}

Ship::Ship(const Ship &s) : health(s.health), weap(s.weap) 
{
     // XXX a corriger
}

Ship &Ship::operator=(const Ship &s)
{
    if (this != &s) {
        this->health = s.health;
        this->weap = s.weap; // XXX a corriger si Weapon a besoin d'une logique de copie
    }
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

