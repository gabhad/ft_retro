#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ncurses.h>

int main(void)
{
 //   WINDOW *boite;

    const char *msg = "Texte au centre";
    int taille = strlen(msg);

    initscr();
    while(1) {
        clear();
        mvprintw(LINES/2, COLS/2 - taille/2, "%s", msg);
        refresh();
        if (getch() != 410)
            break;
    }

    endwin();

 //   free(boite);

    return 0;
}