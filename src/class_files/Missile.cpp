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
        this->y -= 1;
    else if (this->direction == "DOWN")
        this->y += 1;
    // XXX ajouter fonction verification si un vaisseau se trouve sur 
    // la route en utilisant
    // la fonction dealsdamage()
}

int    Missile::getDamage() { return this->damage; }

void Missile::setDamage(int dmg) { this->damage = dmg; }

void Missile::setCoord(int x, int y)
{
    this->x = x;
    this->y = y;
}