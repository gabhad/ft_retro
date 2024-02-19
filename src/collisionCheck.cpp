#include "GameEntity.hpp"

void    collisionCheck(GameEntity &Game)
{
    for (int i = 0; i < 30; i++)
    {
        if (Game.getEShipX(i) == Game.getPShipX())
            return;
    }
}