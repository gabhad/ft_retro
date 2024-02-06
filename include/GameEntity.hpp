#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

#include <ncurses.h>
#include "PlayerShip.hpp"

class GameEntity {
private:
    PlayerShip  *ship;

public:
    WINDOW      *ath;
    WINDOW      *gameScreen;

    GameEntity(WINDOW *ath, WINDOW *gameScreen);
    GameEntity(const GameEntity &);
    GameEntity &operator=(const GameEntity &);

    ~GameEntity();

    void    printShip(void);
    void    moveLeft(void);
    void    moveRight(void);
};

#endif  // GAME_ENTITY_HPP