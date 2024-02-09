#ifndef GAME_ENV_HPP
# define GAME_ENV_HPP

#include <ctime>

class GameEnv {
private:
    int                 score;
    int                 time;
    const time_t        CLOCK;

public:
    GameEnv();
    GameEnv(const GameEnv &);
    GameEnv &operator=(const GameEnv &);

    ~GameEnv();

    int returnTime(void);
    int returnScore(void);

    void    updateTime(void);
    void    updateScore(int n);
};

#endif  // GAME_ENV_HPP