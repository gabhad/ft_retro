#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

#include <ncurses.h>
#include "PlayerShip.hpp"

class GameEntity {
private:
    WINDOW      *ath;
    WINDOW      *gameScreen;
    PlayerShip  *ship;

public:
    GameEntity(WINDOW *ath, WINDOW *gameScreen);
    GameEntity(const GameEntity &);
    GameEntity &operator=(const GameEntity &);

    ~GameEntity();
};

#endif  // GAME_ENTITY_HPP