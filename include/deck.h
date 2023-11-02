#ifndef DECK
#define DECK

#include "card.h"

using namespace std;

class Deck: public Card{
    //private:
    public:
        std::vector<Card> cards;
            
        //Deck();
        //Deck(std::vector<Card> cards);
        void PrintDeck();
        void SetupCards();
        void shuffle();
       
   
};

#endif