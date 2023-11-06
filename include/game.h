#ifndef GAME
#define GAME

#include "../include/deck.h"
#include "../include/card.h"
#include "../include/player.h"

using namespace std;

class Game{
    public:
        Deck cards_deck;
        vector<Player> players;
        Player* player1;

        vector<Card> cards_on_table;

     
        void game_play();  
        void print_players(std::vector<Player> players, int);

        void play_card(Player* player);  
};
#endif