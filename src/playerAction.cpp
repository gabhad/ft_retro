#include "GameEntity.hpp"

void    playerAction(GameEntity &Game, int i)
{
    if (i == KEY_LEFT)
        Game.moveLeft();
    else if (i == KEY_RIGHT)
        Game.moveRight();
    else if (i == KEY_UP)
        Game.moveUp();
    else if (i == KEY_DOWN)
        Game.moveDown();
    else if (i == 32)
        Game.shoots();
}