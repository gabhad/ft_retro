#include "GameEntity.hpp"
#include "ft_retro.hpp"

int    endGame(GameEntity &Game)
{
    while (1) {
        clear();
        mvprintw(LINES / 2 - 2, COLS/2 - 4, 
                "GAME OVER");
        mvprintw(LINES / 2 + 2, COLS / 2 - 20,
                "Felicitations, vous avez marque %d points", Game.returnScore());
        mvprintw(LINES / 2 + 5, COLS / 2 - 30,
                "Appuyez sur Espace pour rejouer ou Echap pour quitter le jeu.");
        refresh();
        int i = getch();
        if (i == 27)
            break;
        else if (i == 32){
            return 1;
        }
    }
    clear();
    return 0;
}