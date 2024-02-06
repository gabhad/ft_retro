#include "GameEntity.hpp"

GameEntity::GameEntity(WINDOW *ath, WINDOW *gameScreen) 
{
    this->ath = ath;
    this->gameScreen = gameScreen;
    
    PlayerShip  *ship = new PlayerShip;
    this->ship = ship;
}

GameEntity::GameEntity(const GameEntity &G) {(void)G;}

GameEntity &GameEntity::operator=(const GameEntity &G) {(void) G; return *this;}

GameEntity::~GameEntity() {}

void    GameEntity::printShip(void)
{
    this->ship->printShip(this->gameScreen, this->ship->accessPosition());
}

void    GameEntity::moveLeft()
{
    this->ship->moveLeft();
}

void    GameEntity::moveRight()
{
    this->ship->moveRight();
}