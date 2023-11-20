#ifndef DECK
#define DECK

#include "../include/card.h"


using namespace std;

class Deck {
    private:
        vector<Card> cards;
        vector<Card> hand;
    public:
       
       
        //Deck();
        //Deck(std::vector<Card> cards);
        void PrintDeck();
        void SetupCards();
        void shuffle();

        vector<Card> DealCards(int n);
        void PrintHand();   
};



#endif