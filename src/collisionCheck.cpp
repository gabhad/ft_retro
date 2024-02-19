#include "GameEntity.hpp"

void    collisionCheck(GameEntity &Game)
{
    for (int i = 0; i < 30; i++)
    {
        if (Game.getPShipX() >= Game.getEShipX(i) - 2 && Game.getPShipX() <= Game.getEShipX(i) + 2
            && Game.getPShipY() >= Game.getEShipY(i) - 1 && Game.getPShipY() <= Game.getEShipY(i) + 1)
        {
            Game.getsDamage(1);
            return;
        }
    }
}