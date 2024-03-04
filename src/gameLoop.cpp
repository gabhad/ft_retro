#include "ft_retro.hpp"
#include "GameEntity.hpp"
#include "Missile.hpp"

void    drawBox(GameEntity &Game)
{
    box(Game.ath, 0, 0);
    box(Game.gameScreen, 0, 0);
//    wrefresh(Game.ath);
//    wrefresh(Game.gameScreen);
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
    drawBox(Game);
}

void    shipExplosion(GameEntity &Game)
{
   // timeout(100);
    time_t  startTime = time(nullptr);
    while (time(nullptr) - startTime < 5) 
    {
        while (Game.checkSize())
            resize_screen(Game);
        clear();
        printElements(Game);
        drawBox(Game);
        Game.printShips();
        mvwprintw(Game.gameScreen, Game.getPShipY() - (time(nullptr) - startTime), Game.getPShipX() - (time(nullptr) - startTime), "*");
        mvwprintw(Game.gameScreen, Game.getPShipY() - (time(nullptr) - startTime), Game.getPShipX() + (time(nullptr) - startTime), "*");
        mvwprintw(Game.gameScreen, Game.getPShipY() + (time(nullptr) - startTime), Game.getPShipX() - (time(nullptr) - startTime), "*");
        mvwprintw(Game.gameScreen, Game.getPShipY() + (time(nullptr) - startTime), Game.getPShipX() + (time(nullptr) - startTime), "*");
        refresh();
        napms(1000);
    }
    clear();
}

void    gameLoop(GameEntity &Game)
{
        timeout(0);
        time_t  lastMoveTime = time(nullptr);
        drawBox(Game);

        while (1) {
        while (Game.checkSize())
            resize_screen(Game);
        
        werase(Game.ath);
        werase(Game.gameScreen);
        drawBox(Game);

        updateATH(Game);
        Game.printShips();
        if (time(nullptr) - lastMoveTime >= 2)
            lastMoveTime = Game.moveEnemies();
        Game.enemyShoots();
        Game.printMissile();
        collisionCheck(Game);
        Game.updateMissiles();

        wrefresh(Game.ath);
        wrefresh(Game.gameScreen);
        refresh();

        if (!Game.getHealth()) {
            shipExplosion(Game);
            break;
        }

        int i = getch();
        if (i == 27 || Game.returnTime() < 0 || Game.eShipCount() == 30)
        {
            clear();
            break;
        }
        else if (i != ERR)
            playerAction(Game, i);

        napms(50);
    }
}