
#include "../include/game.h"
#include <gtest/gtest.h>

Game game;

TEST(Tests_player, WIN){
    cout << "WIN" << endl;

    game.cards_deck.SetupCards();
    game.cards_deck.shuffle();  

    vector<Card> test;    

    vector<Player> p;
    for (int i = 0; i < 4; i++)
        p.push_back( Player("player", test) );
    

    p[0].score = 100;
    p[1].score = -20;  
    p[2].score = -10;
    p[3].score = 40;

    p[0].bet = 0;

    EXPECT_EQ(
        0,
        game.final_winner(p)    
    );
}