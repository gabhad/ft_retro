#include "EnemyShip.hpp"

EnemyShip::EnemyShip() {}
EnemyShip::EnemyShip(const EnemyShip &p) : IShip(p) {(void)p;}
EnemyShip &EnemyShip::operator=(const EnemyShip &p) {(void)p; return *this;}

EnemyShip::~EnemyShip() {}

void    EnemyShip::moveLeft(void) {}
void    EnemyShip::moveRight(void) {}

void    EnemyShip::dies() {}