CC = g++
CC_FLAGS = -g -std=c++11 -DDEBUG

CC_FILES = $(wildcard src/*.cpp)
BIN_FILES = $(patsubst src/%.cpp, %, $(CC_FILES))

all: $(patsubst %, %.exe,$(BIN_FILES))

%.exe: src/%.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

clean: 
	rm -f $(patsubst %, %.exe, $(BIN_FILES))
