
#include "../include/game.h"
#include "../include/deck.h"
#include "../include/card.h"
#include "../include/player.h"

using namespace std;

int main(){
    srand(time(0));
    Game g;

    //Deck deck;
    //deck.SetupCards();
    //deck.shuffle();
    
    //deck.PrintDeck();

    //deck.DealCards(10);
    //deck.PrintHand();
    
    g.game_play();
    //g.print_players();
    //std::cout << std::endl;
    return 0;
    
}
