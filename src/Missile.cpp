#include "Missile.hpp"

Missile::Missile(int dmg, std::string dir, int x, int y) 
{
    this->damage = dmg;
    this->direction = dir;
    this->x = x;
    this->y = y;
}

Missile::Missile(const Missile &) {}
Missile &Missile::operator=(const Missile &m) {(void) m; return *this;}

Missile::~Missile() {}

void Missile::dealsDamage(IShip *ship) 
{
    (void) ship;
}