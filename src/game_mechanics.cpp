#include "ft_retro.hpp"
#include "GameEntity.hpp"
#include <ncurses.h>

void    start_game(void) {
    clear();
    WINDOW  *ath = subwin(stdscr, 3, COLS, 0, 0);
    WINDOW  *gameScreen = subwin(stdscr, LINES - 3, COLS, 3, 0);

    GameEntity *Game = new GameEntity(ath, gameScreen);

    clear();
    delwin(ath) ;
    delwin(gameScreen);
    delete Game;
}