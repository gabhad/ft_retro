#include "PlayerShip.hpp"

PlayerShip::PlayerShip() {
    this->position = COLS / 2 - 2;
}

PlayerShip::PlayerShip(const PlayerShip &p) : IShip(p) {(void) p;}
PlayerShip &PlayerShip::operator=(const PlayerShip &p) {(void) p; return *this;}

PlayerShip::~PlayerShip() {}

void    PlayerShip::moveLeft(void) {
    this->position -= 1;
}
void    PlayerShip::moveRight(void) {
    this->position += 1;
}
void    PlayerShip::dies(void) {}

void    PlayerShip::printShip(WINDOW *win, int position) 
{
    mvwprintw(win, LINES - 4, position, "%s", this->name1);
    mvwprintw(win, LINES - 3, position, "%s", this->name2);
    mvwprintw(win, LINES - 2, position, "%s", this->name3);
}