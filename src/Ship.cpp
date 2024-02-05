#include "Ship.hpp"

IShip::IShip() {}
IShip::IShip(const IShip &) {}
IShip &IShip::operator=(const IShip &) {return *this;}

IShip::~IShip() {}


void    IShip::changesWeapon(Weapon newWeap) 
{
    this->weap = newWeap;
}

void    IShip::shootsMissile(void)
{

}

void    IShip::getsDamage(int dmg) 
{
    this->health -= dmg;
    if (this->health <= 0)
        dies();
}

void    IShip::moveLeft(void){} 
void    IShip::moveRight(void){}
