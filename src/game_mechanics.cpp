#include "ft_retro.hpp"
#include "GameEntity.hpp"
#include <ncurses.h>

void    start_game(void) {
    clear();
    WINDOW  *ath = subwin(stdscr, 3, COLS, 0, 0);
    WINDOW  *gameScreen = subwin(stdscr, LINES - 3, COLS, 3, 0);

    GameEntity *Game = new GameEntity(ath, gameScreen);

    while (1) {
        clear();
        box(Game->ath, ACS_VLINE, ACS_HLINE);
        box(Game->gameScreen, ACS_VLINE, ACS_HLINE);
        wrefresh(Game->ath);
        wrefresh(Game->gameScreen);
        Game->printShip();
        Game->updateMissiles();
        int i = getch();
        if (i == 27)
            break;
        else if (i == KEY_LEFT)
            Game->moveLeft();
        else if (i == KEY_RIGHT)
            Game->moveRight();
        else if (i == 32)
            Game->shoots();
    }

    clear();
    delwin(ath) ;
    delwin(gameScreen);
    delete Game;
}