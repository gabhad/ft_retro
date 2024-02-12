CC = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++20
LDFLAGS = -lncurses
INCLUDES = include/
SRC = src/main.cpp \
		src/launchScreen.cpp \
		src/startGame.cpp \
		src/gameLoop.cpp \
		src/updateATH.cpp \
		src/playerAction.cpp \
		src/endGame.cpp \
		src/BackgroundElement.cpp \
		src/EnemyShip.cpp \
		src/GameEntity.cpp \
		src/GameEnv.cpp \
		src/Missile.cpp \
		src/PlayerShip.cpp \
		src/Ship.cpp \
		src/Weapon.cpp 
TARGET = ft_retro

all: $(TARGET)

$(TARGET):	$(SRC)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $^ -o $@ $(LDFLAGS)

clean:
	@rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean