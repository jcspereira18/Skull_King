
#include "../include/deck.h"

void Deck::SetupCards(){
    Card c;

    for( int j = (int)Numbers::one; j <= (int)Numbers::thirteen; j++ ){
        for( int i = (int)Colors:: red; i <= (int)Colors::black; i++ ){
            c.color = (Colors)i;
            c.number = (Numbers)j;
            c.value = (int)c.number;  
            cards.push_back(c);
        }
    }

    for ( int i = (int)Numbers::fourteen ; i <= (int)Numbers::seventeen; i++){
        if ( i == (int)Numbers::fourteen || i == (int)Numbers::sixteen ){
            for (int x = 0 ; x < 5; x++){
                c.number = (Numbers)i;
                c.value = (int)c.number;
                c.color = white;
                cards.push_back(c);
            }
        }
        else if ( i == (int)Numbers::fifteen ){
            for (int x = 0 ; x < 2; x++){
                c.number = (Numbers)i;
                c.value = (int)c.number;
                c.color = white;
                cards.push_back(c);
            }
        }
        else{
            c.number = (Numbers)i;
            c.value = (int)c.number;
            c.color = white;
            cards.push_back(c);
        }
    }
}

void Deck::shuffle(){
    random_shuffle(cards.begin(), cards.end());
}

void Deck::PrintDeck(){
    for (int i = 0; i < cards.size(); i++){
        cards[i].PrintCard();
    }
}

vector<Card> Deck::DealCards(int n){

    hand.clear();

    for (int j = 0; j < n; j++){
        hand.push_back(cards.back());
        cards.pop_back();
    }
    return hand;
}

void Deck::PrintHand(){
    std::cout << "Your hand: " << std::endl;
    for (int i = 0; i < hand.size(); i++){
        hand[i].PrintCard();
    }
    std::cout << std::endl;
}

