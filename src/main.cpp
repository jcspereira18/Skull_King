
#include "deck.h"
#include "card.h"

int main(){
    srand(time(0));

    Deck deck;
    deck.SetupCards();
    deck.shuffle();
    deck.PrintDeck();
    return 0;
}
