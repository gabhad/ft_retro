#include "Missile.hpp"
#include "GameEntity.hpp"

Missile::Missile(int dmg, std::string dir, int x, int y)
{
    this->damage = dmg;
    this->direction = dir;
    this->x = x;
    this->y = y;
}

Missile::Missile() {}
Missile::Missile(const Missile &) {}
Missile &Missile::operator=(const Missile &m) {(void) m; return *this;}

Missile::~Missile() {}

void    Missile::dealsDamage(IShip *ship) 
{
    (void) ship; // XXX A Voir
}

void    Missile::printMissile(GameEntity &Game) 
{
    if (this->damage == 0)
        return;
    if (this->direction == "UP")
    {
        mvwprintw(Game.gameScreen, x, y, "^");
        mvwprintw(Game.gameScreen, x + 2, y, "^");
    }
    else if (this->direction == "DOWN")
    {
        mvwprintw(Game.gameScreen, x, y, "v");
        mvwprintw(Game.gameScreen, x + 2, y, "v");
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
    // XXX ajouter fonction verification si un vaisseau se trouve sur la route en utilisant
    // XXX la fonction dealsdamage()
}

int    Missile::getDamage() { return this->damage; }

void Missile::setDamage(int dmg) { damage = dmg; }

void Missile::setCoord(int x, int y)
{
    this->x = x;
    this->y = y;
}