#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

#include <ncurses.h>
#include "PlayerShip.hpp"
#include "EnemyShip.hpp"
#include "GameEnv.hpp"

class GameEntity {
private:
    PlayerShip  *pShip;
    EnemyShip   *eShips;
    GameEnv     *Env;
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

    // Ship Functions
    void    printShip(void);
    void    moveLeft(void);
    void    moveRight(void);
    void    moveUp(void);
    void    moveDown(void);
    void    moveEnemies(void);
    void    shoots(void);
    int     getHealth(void);

    void    updateMissiles(void);

    // ATH Functions
    int     returnTime(void);
    int     returnScore(void);
    void    updateTime(void);
    void    updateScore(int n);
};

#endif  // GAME_ENTITY_HPP