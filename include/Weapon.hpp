#ifndef WEAPON_H
    #define WEAPON_H

class Weapon
{
private:
        int damage;
        int ammo;

public:
    Weapon();
    ~Weapon();

    void    shoots(void);

};

#endif