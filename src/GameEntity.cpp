#include "GameEntity.hpp"

GameEntity::GameEntity(WINDOW *ath, WINDOW *gameScreen) {
    box(ath, ACS_VLINE, ACS_HLINE);
    box(gameScreen, ACS_VLINE, ACS_HLINE);
    PlayerShip  *ship = new PlayerShip;
    this->ship = ship;
    
    while (1) {
        wrefresh(ath);
        wrefresh(gameScreen);
        while (int i = getch())
        {
            if (i == 27)
                break;
            else if (i == KEY_LEFT)
                mvwprintw(gameScreen, 1, 1, "Vous avez appuye sur gauche");
            else if (i == KEY_RIGHT)
                mvwprintw(gameScreen, 1, 1, "Vous avez appuye sur droite");
        }
    }
}

GameEntity::GameEntity(const GameEntity &G) {(void)G;}

GameEntity &GameEntity::operator=(const GameEntity &G) {(void) G; return *this;}

GameEntity::~GameEntity() {}