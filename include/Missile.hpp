#ifndef MISSILE_HPP
# define MISSILE_HPP

#include <string>

class GameEntity;

class Missile {
private:
    int         damage;
    std::string direction;
    int         x;
    int         y;
public:
    Missile();
    Missile(int, std::string, int, int);
    Missile(const Missile &);
    Missile &operator=(const Missile &);

    ~Missile();

    void    printMissile(GameEntity &);
    void    updateMissiles();

    // Getter
    int     getDamage();

    // Setter
    void    setDamage(int dmg);
    void    setCoord(int x, int y);
};

#endif  // MISSILE_HPP