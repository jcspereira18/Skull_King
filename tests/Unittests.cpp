#include "../include/Example.hpp"

#include "../include/game.h"

#include <gtest/gtest.h>

Game g;
Card c;

TEST(ExampleTests, WIN){

    g.cards_deck.SetupCards();
    g.cards_deck.shuffle();

    cout << "WIN" << endl;
    vector<Player> p;
    for (int i = 0; i < 4; i++)
        p.push_back( Player("player", g.cards_deck.DealCards(10)) );
    

    p[0].score = 100;
    p[1].score = -20;  
    p[2].score = -10;
    p[3].score = 40;

    EXPECT_EQ(
        0,
        g.final_winner(p)
    );
}


//TEST(ExampleTests2, Square) {
//    int x = 5;
//    int ex = x * x;
//    EXPECT_EQ(
//        ex,
//        Square(x)
//    );
//}