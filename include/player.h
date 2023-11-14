#ifndef PLAYER
#define PLAYER

#include "../include/deck.h"
 using namespace std;

class Player{
    public:
        string name;
        vector<Card> hand;
        int points = 0;
        int score = 0;
        int bet = 0;

        Player(string name, vector<Card> hand);
        //Player(int bet);
        void set_bet(int bet){
            this->bet = bet;
        }
               
        Card pop_card(int index){
            Card popped_card = hand[index];
            hand.erase(hand.begin() + index);
            return popped_card;
        }

        Card push_card(int index){
            Card pushed_card = hand[index];
            return pushed_card;
        }
};

#endif