#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

#include <ncurses.h>
#include "PlayerShip.hpp"
#include "GameEnv.hpp"

class GameEntity {
private:
    WINDOW    *ath;
    WINDOW    *gameScreen;

    PlayerShip  *ship;
    GameEnv     *Env;
    int         sizeLine;
    int         sizeCols;

public:
    GameEntity(WINDOW *ath, WINDOW *gameScreen);
    GameEntity(const GameEntity &);
    GameEntity &operator=(const GameEntity &);

    ~GameEntity();

    // Getters
    WINDOW  *getATH(void);
    WINDOW  *getGameScreen(void);
    bool    checkSize(void);
    void    getSize(void);

    // Ship Functions
    void    printShip(void);
    void    moveLeft(void);
    void    moveRight(void);
    void    moveUp(void);
    void    moveDown(void);
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