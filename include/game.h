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
        Player* player1;
     
        void game_play();  
        void print_players(std::vector<Player> players, int);

        void play_card(Player* player);  
};
#endif