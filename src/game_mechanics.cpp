#include "ft_retro.hpp"
#include "GameEntity.hpp"
#include "GameEnv.hpp"
#include <ncurses.h>

void    resize_screen(GameEntity &Game)
{
    clear();
    mvprintw(LINES / 2 - 2, COLS/2 - 26, 
            "Le terminal actuel comporte %d lignes et %d colonnes", LINES, COLS);
    Game.getSize();
    //wrefresh(stdscr);
    getch();
}

void    start_game(void) {
    WINDOW  *ath = derwin(stdscr, 3, COLS, 0, 0);
    WINDOW  *gameScreen = derwin(stdscr, LINES - 3, COLS, 3, 0);

    GameEntity  *Game = new GameEntity(ath, gameScreen);

    while (1) {
        while (Game->checkSize())
            resize_screen(*Game);
        endwin();
        refresh();
        clear();
        box(Game->getATH(), ACS_VLINE, ACS_HLINE);
        //box(Game->getGameScreen(), ACS_VLINE, ACS_HLINE);
        Game->printShip();
        Game->updateMissiles();
        updateATH(*Game);
        wrefresh(Game->getATH());
        wrefresh(Game->getGameScreen());
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