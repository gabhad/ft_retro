#include "GameEntity.hpp"
#include "Missile.hpp"

GameEntity::GameEntity(WINDOW *ath, WINDOW *gameScreen)
{
    this->ath = ath;
    this->gameScreen = gameScreen;
    sizeLine = LINES;
    sizeCols = COLS;
    
    pShip = new PlayerShip;
    Env = new GameEnv;
    eShips = new EnemyShip[30];

    pMissile = new Missile[10];
    for (int i = 0; i < 10; ++i) { pMissile[i] = Missile(0, "UP", 0, 0); }
    eMissile = new Missile [50];
    for (int i = 0; i < 50; ++i) { eMissile[i] = Missile(0, "DOWN", 0, 0); }

    this->eShips->resetCount();
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

int GameEntity::getPShipX(void)
{
    return this->pShip->getPositionX();
}
int GameEntity::getPShipY(void)
{
    return this->pShip->getPositionY();
}
int GameEntity::getEShipX(int i)
{
    return this->eShips[i].getPositionX();
}
int GameEntity::getEShipY(int i)
{
    return this->eShips[i].getPositionY();
}

time_t GameEntity::getPShipLastDamage(void) { return this->pShip->getLastDamage(); }

void    GameEntity::printShips(void)
{
    this->pShip->printShip(this->gameScreen, *(this->pShip));
    for (int i = 0; i < 30; i++)
        this->eShips->printShip(this->gameScreen, this->eShips[i]);
}

void    GameEntity::moveLeft() { this->pShip->moveLeft(); }
void    GameEntity::moveRight() { this->pShip->moveRight(); }
void    GameEntity::moveUp() { this->pShip->moveUp(); }
void    GameEntity::moveDown() { this->pShip->moveDown(); }
time_t  GameEntity::moveEnemies()
{
    if (this->returnTime() % 4 == 2 || this->returnTime() % 4 == 3)
        for(int i = 0; i < 30; i++)
            this->eShips[i].moveDownRight();
    else
        for(int i = 0; i < 30; i++)
            this->eShips[i].moveDownLeft();
    return time(nullptr);
}

void    GameEntity::shoots() { this->pShip->shootsMissile(); } // XXX reflechir a comment ecrire

int     GameEntity::getHealth() { return this->pShip->getHealth(); }

void    GameEntity::getsDamage(int dmg)
{
    if (time(nullptr) - this->getPShipLastDamage() > 2)
        this->pShip->getsDamage(dmg);
}

void    GameEntity::updateMissiles() // Permet de scanner a chaque tour de boucle les missiles existants et les deplace
{
    for (int i = 0; i < 10; i++) { this->pMissile[i].updateMissiles(); }
    for (int i = 0; i < 50; i++) { this->eMissile[i].updateMissiles(); }
}

int     GameEntity::returnTime(void) { return this->Env->returnTime(); }
int     GameEntity::returnScore(void) { return this->Env->returnScore(); }
void    GameEntity::updateTime(void) { this->Env->updateTime(); }
void    GameEntity::updateScore(int n) { this->Env->updateScore(n); }
