#ifndef DEFAULT_WEAPON_HPP
# define DEFAULT_WEAPON_HPP

#include "Weapon.hpp"

class DefaultWeapon : public IWeapon
{
private:
    int damage = 1;
    int ammo = -1;
public:
    DefaultWeapon();
    ~DefaultWeapon();
};

#endif