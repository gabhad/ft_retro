CC = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++17
LDFLAGS = -lncurses
INCLUDES = /include/
SRC = src/main.cpp
TARGET = ft-retro

all: $(TARGET)

$(TARGET): 
	@$(CC) $(CFLAGS) $(SRC) -I$(INCLUDES)$^ -o $@ $(LDFLAGS)

clean:
	@rm -f $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean