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

void    Weapon::shoots(int damage, std::string direction, int x, int y)
{
    Missile *miss = new Missile(damage, direction, x, y);
    if (this->ammo >= 0)
        this->ammo -= 1;
    if (this-> ammo == 0)
        this->out_of_ammo(); // XXX a coder si besoin
    (void)miss;
}

int     Weapon::getDamage(void) { return this->damage; }

void    Weapon::out_of_ammo(void) {}