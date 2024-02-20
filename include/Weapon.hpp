#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
private:
    int damage;
    int ammo;

public:
    Weapon(int dmg, int ammo);
    Weapon(const Weapon &);
    Weapon &operator=(const Weapon &);

    ~Weapon();

    void    shoots(void);
    int     getDamage(void);
    int     getAmmo(void);
    void    out_of_ammo(void);
};

#endif  // WEAPON_HPP