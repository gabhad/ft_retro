#include "GameEnv.hpp"

GameEnv::GameEnv()
{
    this->score = 0;
    this->time = 100;
}

GameEnv::GameEnv(const GameEnv &) {}
GameEnv &GameEnv::operator=(const GameEnv &) {return *this;}

GameEnv::~GameEnv() {}

