#include "Weapon.hpp"
#include "Missile.hpp"

Weapon::Weapon(int dmg, int ammo) : damage(dmg), ammo(ammo) {}
Weapon::Weapon(const Weapon &w) : damage(w.damage), ammo(w.ammo) {}
Weapon &Weapon::operator=(const Weapon &) {return *this;}

Weapon::~Weapon() {}

void    Weapon::shoots(void)
{
    if (ammo == 0) {
        out_of_ammo(); // XXX a coder si besoin
        return;
    }
    if (ammo >= 0)
        ammo -= 1;
}

int     Weapon::getDamage(void) { return this->damage; }
int     Weapon::getAmmo(void) { return this-> ammo; }

void    Weapon::out_of_ammo(void) {}