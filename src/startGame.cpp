#include "ft_retro.hpp"
#include "GameEntity.hpp"
#include <ncurses.h>

void    start_game(void) {
    WINDOW  *ath = derwin(stdscr, 3, COLS, 0, 0);
    WINDOW  *gameScreen = derwin(stdscr, LINES - 3, COLS, 3, 0);

    GameEntity  *Game = new GameEntity(ath, gameScreen);
    gameLoop(*Game);
    delwin(ath) ;
    delwin(gameScreen);
    endGame(*Game); //XXX reflechir a comment lancer la fonction game over sans entrer dans infinite loop
                    // ni fuite de memoire
    delete Game;
}