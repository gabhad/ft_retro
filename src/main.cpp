#include <ncurses.h>
#include "ft_retro.hpp"

int main(void) {
    initscr();
    keypad(stdscr, TRUE); 
    curs_set(0);
    check_term_size();
    endwin();
    return 0;
}