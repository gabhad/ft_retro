#include "GameEntity.hpp"

GameEntity::GameEntity(WINDOW *ath, WINDOW *gameScreen)
{
    box(ath, ACS_VLINE, ACS_HLINE);
    box(gameScreen, ACS_VLINE, ACS_HLINE);
    
    while (1) {
        wrefresh(ath);
        wrefresh(gameScreen);
        if (int i = getch())
            mvwprintw(gameScreen, 1, 1, "Vous avez appuye sur %d", i);
    }
}

GameEntity::~GameEntity()
{
}
