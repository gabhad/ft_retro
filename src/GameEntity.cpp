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

GameEntity::~GameEntity() 
{
    delete this->ship;
}

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

void    GameEntity::shoots()
{
    this->ship->shootsMissile();
    mvwprintw(this->gameScreen, LINES - 8, this->ship->accessPosition(), "*");
    mvwprintw(this->gameScreen, LINES - 8, this->ship->accessPosition() + 5, "*");
}

void    GameEntity::updateMissiles() // Permet de scanner a chaque tour de boucle les missiles existants et les deplace
{
    // Stocker tous les missiles tires dans un array de missiles, avec leurs coordonnees
    // Les avancer selon leur direction de 1 a chaque iteration
    // Si LINES du missile = LINES d'un vaisseau 
    // => appliquer dommage sur le vaisseau
}