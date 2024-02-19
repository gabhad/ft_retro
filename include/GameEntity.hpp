#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

#include <ncurses.h>
#include "PlayerShip.hpp"
#include "EnemyShip.hpp"
#include "GameEnv.hpp"
#include "Missile.hpp"

class GameEntity {
private:
    PlayerShip  *pShip;
    EnemyShip   *eShips;
    GameEnv     *Env;

    Missile     *pMissile;
    Missile     *eMissile;

    int         sizeLine;
    int         sizeCols;

public:
    GameEntity(WINDOW *ath, WINDOW *gameScreen);
    GameEntity(const GameEntity &);
    GameEntity &operator=(const GameEntity &);

    ~GameEntity();

    WINDOW    *ath;
    WINDOW    *gameScreen;

    // Getters
    bool    checkSize(void);
    void    getSize(void);
    int     getPShipX(void);
    int     getPShipY(void);
    int     getEShipX(int i);
    int     getEShipY(int i);
    time_t  getPShipLastDamage(void);

    // Ship Functions
    void    printShips(void);
    void    moveLeft(void);
    void    moveRight(void);
    void    moveUp(void);
    void    moveDown(void);
    time_t  moveEnemies(void);
    void    shoots(void);
    int     getHealth(void);
    void    getsDamage(int dmg);

    void    updateMissiles(void);

    // ATH Functions
    int     returnTime(void);
    int     returnScore(void);
    void    updateTime(void);
    void    updateScore(int n);
};

#endif  // GAME_ENTITY_HPP