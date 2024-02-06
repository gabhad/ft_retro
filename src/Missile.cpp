#include "Missile.hpp"

Missile::Missile(int dmg, std::string dir) 
{
    this->damage = dmg;
    this->direction = dir;
}

Missile::Missile(const Missile &) {}
Missile &Missile::operator=(const Missile &m) {(void) m; return *this;}

Missile::~Missile() {}

void Missile::dealsDamage(IShip *ship) 
{
    (void) ship;
}