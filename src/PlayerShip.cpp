#include "PlayerShip.hpp"

PlayerShip::PlayerShip() {
    this->positionX = COLS / 2 - 2;
    this->positionY = LINES - 8;
    Weapon  *weap = new Weapon(3, -1);
    this->weap = weap;
    this->health = 5;
}

PlayerShip::PlayerShip(const PlayerShip &p) : IShip(p) {(void) p;}
PlayerShip &PlayerShip::operator=(const PlayerShip &p) {(void) p; return *this;}

PlayerShip::~PlayerShip() 
{
    delete this->weap;
}

int    PlayerShip::getPositionX(void)
{
    return this->positionX;
}

int    PlayerShip::getPositionY(void)
{
    return this->positionY;
}

void    PlayerShip::moveLeft(void) {
    this->positionX -= 3;
    if (this->positionX <= 1)
        this->positionX = 1;
}

void    PlayerShip::moveRight(void) {
    this->positionX += 3;
    if (this->positionX >= COLS - 7)
        this->positionX = COLS - 7;
}

void    PlayerShip::moveUp(void) {
    this->positionY -= 3;
    if (this->positionY <= 1)
        this->positionY = 1;
}

void    PlayerShip::moveDown(void) {
    this->positionY += 3;
    if (this->positionY >= LINES - 7)
        this->positionY = LINES - 7;
}

void    PlayerShip::dies(void) {}

void    PlayerShip::printShip(WINDOW *win, const PlayerShip &p) 
{
    mvwprintw(win, p.positionY, p.positionX, "%s", this->name1.c_str());
    mvwprintw(win, p.positionY + 1, p.positionX, "%s", this->name2.c_str());
    mvwprintw(win, p.positionY + 2, p.positionX + 2, "%s", this->name3.c_str());
}

void    PlayerShip::shootsMissile(void)
{
    this->weap->shoots(this->weap->getDamage(), "UP", this->positionX, LINES - 8);
}

int     PlayerShip::getHealth(void)
{
    return this->health;
}