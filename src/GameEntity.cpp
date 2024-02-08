#include "GameEntity.hpp"

GameEntity::GameEntity(WINDOW *ath, WINDOW *gameScreen) 
{
    this->ath = ath;
    this->gameScreen = gameScreen;
    this->sizeLine = LINES;
    this->sizeCols = COLS;
    
    PlayerShip  *ship = new PlayerShip;
    this->ship = ship;

    GameEnv     *Env = new GameEnv;
    this->Env = Env;
}

GameEntity::GameEntity(const GameEntity &G) {(void)G;}
GameEntity &GameEntity::operator=(const GameEntity &G) {(void) G; return *this;}

GameEntity::~GameEntity() 
{
    delete this->ship;
    delete this->Env;
}

WINDOW  *GameEntity::getATH(void) 
{
    return this->ath;
}

WINDOW  *GameEntity::getGameScreen(void) 
{
    return this->gameScreen;
}

bool    GameEntity::checkSize(void)
{
    if (LINES != this->sizeLine || COLS != this->sizeCols)
        return 1;
    return 0;
}

void    GameEntity::getSize(void)
{
    mvprintw(LINES / 2, COLS/2 - 35, 
            "Votre jeu est actuellement configure pour %d lignes et %d colonnes", this->sizeLine, this->sizeCols);
}

void    GameEntity::printShip(void)
{
    this->ship->printShip(this->gameScreen, *(this->ship));
}

void    GameEntity::moveLeft()
{
    this->ship->moveLeft();
}

void    GameEntity::moveRight()
{
    this->ship->moveRight();
}

void    GameEntity::moveUp()
{
    this->ship->moveUp();
}

void    GameEntity::moveDown()
{
    this->ship->moveDown();
}

void    GameEntity::shoots()
{
    this->ship->shootsMissile();
    mvwprintw(this->gameScreen, LINES - 8, this->ship->getPositionX(), "*");
    mvwprintw(this->gameScreen, LINES - 8, this->ship->getPositionX() + 5, "*");
}

int     GameEntity::getHealth()
{
    return this->ship->getHealth();
}

void    GameEntity::updateMissiles() // Permet de scanner a chaque tour de boucle les missiles existants et les deplace
{
    // Stocker tous les missiles tires dans un array de missiles, avec leurs coordonnees
    // Les avancer selon leur direction de 1 a chaque iteration
    // Si LINES du missile = LINES d'un vaisseau 
    // => appliquer dommage sur le vaisseau
}

int GameEntity::returnTime(void)
{
    return this->Env->returnTime();
}
int GameEntity::returnScore(void)
{
    return this->Env->returnScore();
}

void    GameEntity::updateTime(void)
{
    this->Env->updateTime();
}
void    GameEntity::updateScore(int n)
{
    this->Env->updateScore(n);
}
