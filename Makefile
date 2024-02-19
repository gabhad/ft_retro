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
		src/collisionCheck.cpp \
		src/class_files/BackgroundElement.cpp \
		src/class_files/EnemyShip.cpp \
		src/class_files/GameEntity.cpp \
		src/class_files/GameEnv.cpp \
		src/class_files/Missile.cpp \
		src/class_files/PlayerShip.cpp \
		src/class_files/Ship.cpp \
		src/class_files/Weapon.cpp 
TARGET = ft_retro

all: $(TARGET)

$(TARGET):	$(SRC)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $^ -o $@ $(LDFLAGS)

clean:
	@rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean