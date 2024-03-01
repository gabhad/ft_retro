#include "Missile.hpp"
#include "GameEntity.hpp"

Missile::Missile(int dmg, std::string dir, int x, int y)
    : damage(dmg), direction(dir), x(x), y(y) {}

Missile::Missile() {}
Missile::Missile(const Missile &) {}
Missile &Missile::operator=(const Missile &m) {(void) m; return *this;}

Missile::~Missile() {}

void    Missile::printMissile(GameEntity &Game) 
{
    if (this->damage == 0)
        return;
    if (this->direction == "UP")
    {
        mvwprintw(Game.gameScreen, y, x, "^");
        mvwprintw(Game.gameScreen, y, x + 2, "^");
    }
    else if (this->direction == "DOWN")
    {
        mvwprintw(Game.gameScreen, y, x, "v");
        mvwprintw(Game.gameScreen, y, x + 2, "v");
    }
}

void    Missile::updateMissiles()
{
    if (this->damage == 0)
        return;
    if (this->direction == "UP")
        this->y -= 3;
    else if (this->direction == "DOWN")
        this->y += 3;
}

int     Missile::getDamage() { return damage; }
int     Missile::getMissX() { return x; }
int     Missile::getMissY() { return y; }

void    Missile::setDamage(int dmg) { this->damage = dmg; }
void    Missile::setCoord(int x, int y)
{
    this->x = x;
    this->y = y;
}
void    Missile::setDirection(std::string dir) { direction = dir; }
