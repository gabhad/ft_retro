#include "GameEntity.hpp"

GameEntity::GameEntity(WINDOW *ath, WINDOW *gameScreen)
{
    this->ath = ath;
    this->gameScreen = gameScreen;
    sizeLine = LINES;
    sizeCols = COLS;
    
    pShip = new PlayerShip;
    Env = new GameEnv;
    eShips = new EnemyShip[20];
}

GameEntity::GameEntity(const GameEntity &G) {(void)G;}
GameEntity &GameEntity::operator=(const GameEntity &G) {(void) G; return *this;}

GameEntity::~GameEntity() 
{
    delete this->pShip;
    delete this->Env;
    delete[] this->eShips;
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

void    GameEntity::printShips(void)
{
    this->pShip->printShip(this->gameScreen, *(this->pShip));
    for (int i = 0; i < 20; i++)
        this->eShips->printShip(this->gameScreen, this->eShips[i]);
}

void    GameEntity::moveLeft() { this->pShip->moveLeft(); }
void    GameEntity::moveRight() { this->pShip->moveRight(); }
void    GameEntity::moveUp() { this->pShip->moveUp(); }
void    GameEntity::moveDown() { this->pShip->moveDown(); }
void    GameEntity::moveEnemies()
{
    if (this->returnTime() % 4 == 2 || this->returnTime() % 4 == 3)
        for(int i = 0; i < 20; i++)
            this->eShips[i].moveDownRight();
    else
        for(int i = 0; i < 20; i++)
            this->eShips[i].moveDownLeft();
}

void    GameEntity::shoots()
{
    this->pShip->shootsMissile();
    mvwprintw(this->gameScreen, LINES - 8, this->pShip->getPositionX(), "*");
    mvwprintw(this->gameScreen, LINES - 8, this->pShip->getPositionX() + 5, "*");
}

int     GameEntity::getHealth() { return this->pShip->getHealth(); }

void    GameEntity::updateMissiles() // Permet de scanner a chaque tour de boucle les missiles existants et les deplace
{
    // Stocker tous les missiles tires dans un array de missiles, avec leurs coordonnees
    // Les avancer selon leur direction de 1 a chaque iteration
    // Si LINES du missile = LINES d'un vaisseau 
    // => appliquer dommage sur le vaisseau
}

int     GameEntity::returnTime(void) { return this->Env->returnTime(); }
int     GameEntity::returnScore(void) { return this->Env->returnScore(); }
void    GameEntity::updateTime(void) { this->Env->updateTime(); }
void    GameEntity::updateScore(int n) { this->Env->updateScore(n); }
