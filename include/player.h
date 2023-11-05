#ifndef PLAYER
#define PLAYER

#include "deck.h"
 using namespace std;

class Player{
    public:
        std::string name;
        std::vector<Card> hand;
        
        int points = 0;

        Player(std::string name, std::vector<Card> hand);
         
        void set_name(std::string name);
        void set_points(int points);

        Card pop_card(int index){
            Card popped_card = hand[index];
            hand.erase(hand.begin() + index);
            return popped_card;
        }

};

#endif