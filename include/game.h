#ifndef GAME
#define GAME

#include "../include/deck.h"
//#include "../include/card.h"
#include "../include/player.h"

using namespace std;

#define MAX_PLAYERS 4
#define ROUNDS 1

class Game{
    private:
        int color = -1;
        int max = 0;
        int flag = 0;

    public:
        
        Deck cards_deck;
        vector<Player> players;
        Player* player1;
        vector<Card> cards_on_table;

     
        void game_play();  
        void print_players(vector<Player> players, int i);
        void bet_round();
        void print_bet(vector<Player> players);
        void play_card(Player* player, int i);  
        void print_cards_on_table();
        void color_round(Player* player, int index);
        bool check_color(Player* player, int index);
        int checkwin(vector <Card> cards, int color);
        void order_players(int win_pos);
        void bet_points();
        int final_winner(vector<Player> players);        
};
#endif