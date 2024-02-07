#include "ft_retro.hpp"
#include "GameEntity.hpp"
#include "GameEnv.hpp"
#include <ncurses.h>

void    resize_screen(void)
{
    while (LINES < 40 || COLS < 100) {
        clear();
        mvprintw(LINES/2, COLS/2 - 15, "Merci d'agrandir votre terminal");
        refresh();
        getch();
    }
}

void    start_game(void) {
    clear();
    WINDOW  *ath = subwin(stdscr, 3, COLS, 0, 0);
    WINDOW  *gameScreen = subwin(stdscr, LINES - 3, COLS, 3, 0);

    GameEntity  *Game = new GameEntity(ath, gameScreen);

    while (1) {
        clear();
        // if (LINES < 40 || COLS < 100)
        //     resize_screen();
        box(Game->ath, ACS_VLINE, ACS_HLINE);
        box(Game->gameScreen, ACS_VLINE, ACS_HLINE);
        wrefresh(Game->ath);
        wrefresh(Game->gameScreen);
        Game->printShip();
        Game->updateMissiles();
        updateATH(*Game);
        int i = getch();
        if (i == 27)
            break;
        else if (i == KEY_LEFT)
            Game->moveLeft();
        else if (i == KEY_RIGHT)
            Game->moveRight();
        else if (i == KEY_UP)
            Game->moveUp();
        else if (i == KEY_DOWN)
            Game->moveDown();
        else if (i == 32)
            Game->shoots();

        // XXXCorriger bug en cas de resize le vaisseau sort du box
    }
    clear();
    delwin(ath) ;
    delwin(gameScreen);
    delete Game;
}