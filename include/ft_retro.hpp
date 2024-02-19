#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

#include <ncurses.h>

#include "GameEntity.hpp"

void    check_term_size(void);
void    start_game(void);
void    updateATH(GameEntity &Game);
void    gameLoop(GameEntity &Game);
void    playerAction(GameEntity &Game, int i);
int     endGame(GameEntity &Game);
void    collisionCheck(GameEntity &Game);

#endif  // FT_RETRO_HPP