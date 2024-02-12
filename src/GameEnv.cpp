#include "GameEnv.hpp"

GameEnv::GameEnv() : score(0), time(100), CLOCK(std::time(NULL)) {}
GameEnv::GameEnv(const GameEnv &g) : score(g.score), time(g.time), CLOCK(g.CLOCK) {}
GameEnv &GameEnv::operator=(const GameEnv &) {return *this;}

GameEnv::~GameEnv() {}

int     GameEnv::returnTime(void) { return this->time; }
int     GameEnv::returnScore(void) { return this->score; }

void    GameEnv::updateTime(void) { this->time = 5 - (std::time(NULL) - this->CLOCK); }
void    GameEnv::updateScore(int n) { this->score += n; }
