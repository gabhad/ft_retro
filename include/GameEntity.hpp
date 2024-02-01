#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

#include <ncurses.h>

class GameEntity
{
private:
    WINDOW  *ath;
    WINDOW  *gameScreen;
    
public:
    GameEntity(WINDOW *ath, WINDOW *gameScreen);
    ~GameEntity();
};


#endif