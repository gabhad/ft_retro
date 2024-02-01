#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
protected:
        int damage;
        int ammo;

public:
    Weapon();
    ~Weapon();

    virtual void    shoots(void) = 0;

};

#endif

