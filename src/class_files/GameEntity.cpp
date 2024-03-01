#include "GameEntity.hpp"
#include "Missile.hpp"

#include <iostream>

GameEntity::GameEntity(WINDOW *ath, WINDOW *gameScreen)
{
    this->ath = ath;
    this->gameScreen = gameScreen;
    sizeLine = LINES;
    sizeCols = COLS;
    
    pShip = new PlayerShip;
    Env = new GameEnv;
    eShips = new EnemyShip[30];

    pMissile = new Missile[5];
    eMissile = new Missile [50];

    this->eShips->resetCount();
}

GameEntity::GameEntity(const GameEntity &G) {(void)G;}
GameEntity &GameEntity::operator=(const GameEntity &G) {
    (void) G; return *this;
    }

GameEntity::~GameEntity() 
{
    delete pShip;
    delete Env;
    delete[] eShips;
    delete[] pMissile;
    delete[] eMissile;
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

time_t GameEntity::getPShipLastDamage(void) {
    return this->pShip->getLastDamage(); 
}

void    GameEntity::printShips(void)
{
    this->pShip->printShip(this->gameScreen, *(this->pShip));
    for (int i = 0; i < 30; i++)
        eShips[i].printShip(this->gameScreen);
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

void    GameEntity::shoots() {
    int i = 0;
    if (int dmg = pShip->shootsMissile()) {
        while (pMissile[i].getDamage() > 0)
            i++;
        pMissile[i].setDamage(dmg);
        pMissile[i].setCoord(getPShipX(), getPShipY() - 1);
        pMissile[i].setDirection("UP");
    }
}

void GameEntity::enemyShoots(void)
{
    for (int i = 0; i < 30; i++)
        if (!eShips[i].isDead)
            eShips[i].shootsMissile();
}

void    GameEntity::updateMissiles()
{
    for (int i = 0; i < 5; i++) { 
        this->pMissile[i].updateMissiles();
        if (this->pMissile[i].getMissY() < 0)
            this->pMissile[i].setDamage(0);
    }
    for (int i = 0; i < 50; i++) {
        this->eMissile[i].updateMissiles();
        if (this->eMissile[i].getMissY() > LINES)
            this->eMissile[i].setDamage(0);
        }
}

void GameEntity::printMissile(void)
{
    for (int i = 0; i < 5; i++) { 
        pMissile[i].printMissile(*this); }
    for (int i = 0; i < 50; i++) { 
        eMissile[i].printMissile(*this); }

}

void    GameEntity::checkMissileCollision(void)
{
    for (int i = 0; i < 5; i++) {
        if (pMissile[i].getDamage()) {
            for (int j = 0; j < 30; j++) {
                if (!eShips[j].isDead
                    && pMissile[i].getMissX() >= eShips[j].getPositionX() - 2 
                    && pMissile[i].getMissX() <= eShips[j].getPositionX() + 2
                    && pMissile[i].getMissY() == eShips[j].getPositionY() + 1) {
                        eShips[j].getsDamage(pMissile[i].getDamage());
                        pMissile[i].setDamage(0);
                        updateScore(100);
                } 
            }
        }
    }
}

int     GameEntity::getHealth() { return this->pShip->getHealth(); }

void    GameEntity::getsDamage(int dmg)
{
    if (time(nullptr) - this->getPShipLastDamage() > 2)
        this->pShip->getsDamage(dmg);
}

int     GameEntity::returnTime(void) { return this->Env->returnTime(); }
int     GameEntity::returnScore(void) { return this->Env->returnScore(); }
void    GameEntity::updateTime(void) { this->Env->updateTime(); }
void    GameEntity::updateScore(int n) { this->Env->updateScore(n); }
