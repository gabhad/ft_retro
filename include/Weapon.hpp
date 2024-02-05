#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon {
private:
    int damage;
    int ammo;
public:
    Weapon();
    Weapon(const Weapon &);
    Weapon &operator=(const Weapon &);

    ~Weapon();

    void    shoots(void);
};

#endif  // WEAPON_HPP