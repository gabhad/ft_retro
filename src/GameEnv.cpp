#include "GameEnv.hpp"

GameEnv::GameEnv()
{
    this->score = 0;
    this->time = 100;
}

GameEnv::GameEnv(const GameEnv &) {}
GameEnv &GameEnv::operator=(const GameEnv &) {return *this;}

GameEnv::~GameEnv() {}

int GameEnv::returnTime(void)
{
    return this->time;
}
int GameEnv::returnScore(void)
{
    return this->score;
}

void    GameEnv::updateTime(void)
{
    this->time -= 1;
}
void    GameEnv::updateScore(int n)
{
    this->score += n;
}
