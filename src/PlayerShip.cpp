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
