#ifndef DECK
#define DECK

#include "card.h"
#include "player.h"


using namespace std;

class Deck {
    //private:
    public:
        vector<Card> cards;
        //std::vector<Player> players;
        vector<Card> hand;
       
       
        //Deck();
        //Deck(std::vector<Card> cards);
        void PrintDeck();
        void SetupCards();
        void shuffle();

        vector<Card> DealCards(int n);
        void PrintHand();
        //void PrintDealCards();
   
};



#endif