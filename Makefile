CC = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++17
LDFLAGS = -lncurses
INCLUDES = include/
SRC = src/main.cpp \
		src/launch_screen.cpp \
		src/game_mechanics.cpp \
		src/BackgroundElement.cpp \
		src/EnemyShip.cpp \
		src/GameEntity.cpp \
		src/GameEnv.cpp \
		src/Missile.cpp \
		src/PlayerShip.cpp \
		src/Ship.cpp \
		src/Weapon.cpp 
TARGET = ft-retro

all: $(TARGET)

$(TARGET):	$(SRC)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $^ -o $@ $(LDFLAGS)

clean:
	@rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean