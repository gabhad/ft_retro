#include "ft_retro.hpp"
#include "GameEntity.hpp"
#include "ncurses.h"

void    printElements(GameEntity &Game)
{
    mvwprintw(Game.ath, 1, 2, "SCORE= %d", Game.returnScore());
    mvwprintw(Game.ath, 1, COLS/2, "TIME= %d", Game.returnTime());
    mvwprintw(Game.ath, 1, COLS - 19, "LIVES= ");
    for (int i = 0; i < Game.getHealth(); i++)
        mvwprintw(Game.ath, 1, COLS - 8 - i, "X");
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