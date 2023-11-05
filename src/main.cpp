
#include "game.h"
#include "deck.h"
#include "card.h"
#include "player.h"

using namespace std;

int main(){
    srand(time(0));
    Game g;

    //Deck deck;
    //deck.SetupCards();
    //deck.shuffle();
    
    //deck.PrintDeck();
    std::cout << std::endl;

    //deck.DealCards(10);
    //deck.PrintHand();
    
    g.game_play();
    g.print_players();
    return 0;
    
}
