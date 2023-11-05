#ifndef GAME
#define GAME

#include "deck.h"
#include "card.h"
#include "player.h"

using namespace std;

class Game{
    public:
        Deck cards_deck;
        std::vector<Player> players;
     
        void game_play();  
        void print_players();

};
#endif