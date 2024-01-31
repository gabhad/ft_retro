#include "ft_retro.hpp"
#include <ncurses.h>

void    start_game(void) {
    clear();
    WINDOW  *ath = subwin(stdscr, 3, COLS, 0, 0);
    WINDOW  *gameScreen = subwin(stdscr, LINES - 3, COLS, 3, 0);

    box(ath, ACS_VLINE, ACS_HLINE);
    box(gameScreen, ACS_VLINE, ACS_HLINE);

    wrefresh(ath);
    wrefresh(gameScreen);
    
    if (getch() != 410) {
        delwin(ath);
        delwin(gameScreen);
    }

    clear();
}