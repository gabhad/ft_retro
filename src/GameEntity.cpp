#include "GameEntity.hpp"

GameEntity::GameEntity(WINDOW *ath, WINDOW *gameScreen)
{
    box(ath, ACS_VLINE, ACS_HLINE);
    box(gameScreen, ACS_VLINE, ACS_HLINE);
    
    while (1) {
        wrefresh(ath);
        wrefresh(gameScreen);
        if (getch() == 27)
            break;
        else if (getch() == KEY_LEFT)
            mvwprintw(gameScreen, 1, 1, "Vous avez appuye sur gauche");
        else if (getch() == KEY_RIGHT)
            mvwprintw(gameScreen, 1, 1, "Vous avez appuye sur droite");
    }
}

GameEntity::~GameEntity()
{
}
