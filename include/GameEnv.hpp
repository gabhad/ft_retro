#ifndef GAME_ENV_HPP
# define GAME_ENV_HPP

class GameEnv {
private:
    int     score;
    int     time;

public:
    GameEnv();
    GameEnv(const GameEnv &);
    GameEnv &operator=(const GameEnv &);

    ~GameEnv();
};

#endif  // GAME_ENV_HPP