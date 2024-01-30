#include <ncurses.h>
#include "ft_retro.hpp"

int main(void) {
    initscr();
    check_term_size();
    endwin();
    return 0;
}