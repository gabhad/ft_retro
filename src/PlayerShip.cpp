#include "PlayerShip.hpp"

PlayerShip::PlayerShip() {
    this->position = COLS / 2 - 2;
}

PlayerShip::PlayerShip(const PlayerShip &p) : IShip(p) {(void) p;}
PlayerShip &PlayerShip::operator=(const PlayerShip &p) {(void) p; return *this;}

PlayerShip::~PlayerShip() {}

int    PlayerShip::accessPosition(void)
{
    return this->position;
}

void    PlayerShip::moveLeft(void) {
    this->position -= 3;
}
void    PlayerShip::moveRight(void) {
    this->position += 3;
}
void    PlayerShip::dies(void) {}

void    PlayerShip::printShip(WINDOW *win, int position) 
{
    mvwprintw(win, LINES - 7, position, "%s", this->name1.c_str());
    mvwprintw(win, LINES - 6, position, "%s", this->name2.c_str());
    mvwprintw(win, LINES - 5, position + 2, "%s", this->name3.c_str());
}