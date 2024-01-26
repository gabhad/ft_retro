CC = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++17
LDFLAGS = -lncurses
SRC = src/main.cpp
TARGET = ft-retro

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean