#include "Weapon.hpp"
#include "Missile.hpp"

Weapon::Weapon(int dmg, int ammo) 
{
    this->damage = dmg;
    this->ammo = ammo;
}

Weapon::Weapon(const Weapon &) {}
Weapon &Weapon::operator=(const Weapon &) {return *this;}

Weapon::~Weapon() {}

void    Weapon::shoots(int damage, std::string direction)
{
    Missile *miss = new Missile(damage, direction);
    (void)miss;
}

int     Weapon::getDamage(void)
{
    return this->damage;
}