
#include "../include/game.h"
#include "../include/deck.h"
#include "../include/card.h"
#include "../include/player.h"

using namespace std;

int main(){

    srand(time(0));
    Game g;
    
    g.game_play();

   
    return 0;
    
}

//int main(){
//
//    srand(time(0));
//    Game g; 
//
//
//
//    vector<Card> ch 
//    ch.color = 1;
//    ch.value = 2;
//
//    PrintCard2(ch);
//
//    //for(int i = 0; i < ch.size; i++){
//    //    cards_on_table.pop_back(ch(i));
////
//    //}
//    return 0;
//    
//}
