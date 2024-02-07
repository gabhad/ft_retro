#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

#include <ncurses.h>
#include "PlayerShip.hpp"
#include "GameEnv.hpp"

class GameEntity {
private:
    PlayerShip  *ship;
    GameEnv     *Env;

public:
    WINDOW      *ath;
    WINDOW      *gameScreen;

    GameEntity(WINDOW *ath, WINDOW *gameScreen);
    GameEntity(const GameEntity &);
    GameEntity &operator=(const GameEntity &);

    ~GameEntity();

    // Ship Functions
    void    printShip(void);
    void    moveLeft(void);
    void    moveRight(void);
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