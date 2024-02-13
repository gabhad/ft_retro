#include "GameEntity.hpp"
#include "ft_retro.hpp"
#include "ncurses.h"

void    printElements(GameEntity &Game)
{
    mvwprintw(Game.ath, 1, 2, "SCORE= %d", Game.returnScore());
    mvwprintw(Game.ath, 1, COLS/2 - 5, "TIME= %d", Game.returnTime());
    mvwprintw(Game.ath, 1, COLS - 15, "LIVES= ");
    for (int i = 0; i < Game.getHealth(); i++)
        mvwprintw(Game.ath, 1, COLS - 8 + i, "X");
}

void    updateATH(GameEntity &Game)
{
    printElements(Game);
    Game.updateTime();
}