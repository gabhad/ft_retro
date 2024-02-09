#include "ft_retro.hpp"
#include "GameEntity.hpp"

void    drawBox(WINDOW *win)
{
    box(win, 0, 0);
    wrefresh(win);
}

void    resize_screen(GameEntity &Game)
{
    clear();
    mvprintw(LINES / 2 - 2, COLS/2 - 26, 
            "Le terminal actuel comporte %d lignes et %d colonnes", LINES, COLS);
    Game.getSize();
    getch();
    if (!Game.checkSize()) 
    {
        int newLines = LINES;
        int newCols = COLS;
        delwin(Game.ath);
        delwin(Game.gameScreen);
        Game.ath = derwin(stdscr, 3, newCols, 0, 0);
        Game.gameScreen = derwin(stdscr, newLines - 3, newCols, 3, 0);
        wrefresh(stdscr);    
    }
}

void    gameLoop(GameEntity &Game)
{
        timeout(100);
        while (1) {
        while (Game.checkSize())
            resize_screen(Game);
        clear();
        Game.printShip();
        Game.updateMissiles();
        updateATH(Game);
        drawBox(Game.ath);
        drawBox(Game.gameScreen);

        int i = getch();
        if (i == 27)
            break;
        if (i != ERR)
            playerAction(Game, i);
    }
}