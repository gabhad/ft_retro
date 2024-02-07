#include "PlayerShip.hpp"

PlayerShip::PlayerShip() {
    this->position = COLS / 2 - 2;
    Weapon  *weap = new Weapon(3, -1);
    this->weap = weap;
}

PlayerShip::PlayerShip(const PlayerShip &p) : IShip(p) {(void) p;}
PlayerShip &PlayerShip::operator=(const PlayerShip &p) {(void) p; return *this;}

PlayerShip::~PlayerShip() 
{
    delete this->weap;
}

int    PlayerShip::accessPosition(void)
{
    return this->position;
}

void    PlayerShip::moveLeft(void) {
    this->position -= 3;
    if (this->position <= 1)
        this->position = 1;

}
void    PlayerShip::moveRight(void) {
    this->position += 3;
    if (this->position >= COLS - 7)
        this->position = COLS - 7;
}
void    PlayerShip::dies(void) {}

void    PlayerShip::printShip(WINDOW *win, int position) 
{
    mvwprintw(win, LINES - 10, position, "%s", this->name1.c_str());
    mvwprintw(win, LINES - 9, position, "%s", this->name2.c_str());
    mvwprintw(win, LINES - 8, position + 2, "%s", this->name3.c_str());
}

void    PlayerShip::shootsMissile(void)
{
    this->weap->shoots(this->weap->getDamage(), "UP", this->position, LINES - 8);
}