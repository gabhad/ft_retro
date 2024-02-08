#include "Missile.hpp"

Missile::Missile(int dmg, std::string dir, int x, int y) 
{
    this->damage = dmg;
    this->direction = dir;
    this->x = x;
    this->y = y;
}

Missile::Missile(const Missile &) {}
Missile &Missile::operator=(const Missile &m) {(void) m; return *this;}

Missile::~Missile() {}

void    Missile::dealsDamage(IShip *ship) 
{
    (void) ship;
}

void    Missile::printMissile(Missile &m, GameEntity &Game) 
{
    if (m.direction == "UP")
    {
        mvwprintw(Game.gameScreen, x, y, "^");
        mvwprintw(Game.gameScreen, x, y + 5, "^");
    }
    else if (m.direction == "DOWN")
    {
        mvwprintw(Game.gameScreen, x, y, "v");
        mvwprintw(Game.gameScreen, x, y + 5, "v");
    }
}

void    Missile::updateMissiles(Missile &m)
{
    if (m.direction == "UP")
        m.x -= 3;
    else if (m.direction == "DOWN")
        m.x += 3;
    // XXX ajouter fonction verification si un vaisseau se trouve sur la route en utilisant
    // XXX la fonction dealsdamage()
}