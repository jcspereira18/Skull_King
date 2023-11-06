# -*- Makefile -*-
all:
	g++ ./src/card.cpp ./src/deck.cpp ./src/player.cpp ./src/game.cpp ./src/main.cpp -o ./bin/main

run:
	./bin/main