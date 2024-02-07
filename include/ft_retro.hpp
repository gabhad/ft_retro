#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

#include <ncurses.h>

#include "GameEntity.hpp"

void    check_term_size(void);
void    start_game(void);
void    updateATH(GameEntity &Game);

#endif