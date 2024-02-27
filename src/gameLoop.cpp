#include "ft_retro.hpp"
#include "GameEntity.hpp"
#include "Missile.hpp"

void    drawBox(GameEntity &Game)
{
    box(Game.ath, 0, 0);
    box(Game.gameScreen, 0, 0);
    wrefresh(Game.ath);
    wrefresh(Game.gameScreen);
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
        timeout(200);
        time_t  lastMoveTime = time(nullptr);
        while (1) {
        while (Game.checkSize())
            resize_screen(Game);
        clear();
        Game.printShips();
        if (time(nullptr) - lastMoveTime >= 2)
            lastMoveTime = Game.moveEnemies();
        Game.printMissile();
        collisionCheck(Game);
        Game.updateMissiles();
        updateATH(Game);
        drawBox(Game);

        int i = getch();
        if (i == 27 || Game.returnTime() < 0)
            break;
        else if (i != ERR)
            playerAction(Game, i);
    }
}