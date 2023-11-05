#ifndef PLAYER
#define PLAYER

#include "../include/deck.h"
 using namespace std;

class Player{
    public:
        string name;
        vector<Card> hand;
        
        int points = 0;

        Player(std::string name, std::vector<Card> hand);
         
        void set_name(std::string name);
        void set_points(int points);

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