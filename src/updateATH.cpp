#include "GameEntity.hpp"
#include "ncurses.h"

void    printElements(GameEntity &Game)
{
    mvwprintw(Game.ath, 1, 2, "SCORE= %d", Game.returnScore());
    mvwprintw(Game.ath, 1, COLS/2 - 5, "TIME= %d", Game.returnTime());
    mvwprintw(Game.ath, 1, COLS - 15, "LIVES= ");
    for (int i = 0; i < Game.getHealth(); i++)
        mvwprintw(Game.ath, 1, COLS - 4 - i, "X");
}

void    updateATH(GameEntity &Game)
{
    if (Game.returnTime() == 0)
    {
        // XXX GAME OVER screen
    }
    printElements(Game);
    Game.updateTime();
}