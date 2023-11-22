#include "../include/game.h"

#include <gtest/gtest.h>

Game gm;

TEST(Tests_player, pl){

    vector<Card> test_p1;
    vector<Card> test_p2;
    vector<Card> test_p3;

    vector<Player> players;
    vector<Card> cards_table;

   
    players.push_back(Player("player 1", test_p1));
    players.push_back(Player("player 2", test_p2));
    players.push_back(Player("player 3", test_p3));

    players[0].bet = 0;
    players[1].bet = 1;
    players[2].bet = 2;


    for (int i = 0; i < 3; i++){
        test_p1.push_back(Card());
        test_p2.push_back(Card());
        test_p3.push_back(Card());
    }
    

    test_p1[0].color = red;
    test_p1[0].value = 7;
    test_p1[1].color =black;
    test_p1[1].value = 1;
    test_p1[2].color = blue;
    test_p1[2].value = 9;

    test_p2[0].color = red;
    test_p2[0].value = 2;
    test_p2[1].color = yellow;
    test_p2[1].value = 3;
    test_p2[2].color = white;
    test_p2[2].value = 15;

    test_p3[0].color = red;
    test_p3[0].value = 10;
    test_p3[1].color = yellow;
    test_p3[1].value = 8;
    test_p3[2].color = blue;
    test_p3[2].value = 13;
   

    cards_table.push_back(test_p1[0]);
    cards_table.push_back(test_p2[0]);
    cards_table.push_back(test_p3[0]);

    EXPECT_EQ(
        2,
        gm.checkwin(cards_table, red)    
    );

    players = gm.order_players(gm.checkwin(cards_table, red), players); //return ordered players

    EXPECT_EQ(
        1,
        players[0].points
    );

    cards_table.clear();  //clear table

    cards_table.push_back(test_p3[1]);
    cards_table.push_back(test_p1[1]);
    cards_table.push_back(test_p2[1]);

    EXPECT_EQ(
        1,
        gm.checkwin(cards_table, yellow)    
    );

    players = gm.order_players(gm.checkwin(cards_table, yellow), players); //return ordered players

    EXPECT_EQ(
        1,
        players[0].points
    );

    cards_table.clear();  //clear table

    cards_table.push_back(test_p1[2]);
    cards_table.push_back(test_p2[2]);
    cards_table.push_back(test_p3[2]);

    EXPECT_EQ(
        1,
        gm.checkwin(cards_table, blue)    
    );

    players = gm.order_players(gm.checkwin(cards_table, blue), players); //return ordered players

    EXPECT_EQ(
        1,
        players[0].points
    );

    cards_table.clear();  //clear table

    players = gm.bet_points(players);

    //ordem:    p1   ,    p2  ,    p0
    //       player0 , player1, player2
    EXPECT_EQ(
        20,
        players[0].score
    );

    EXPECT_EQ(
        -10,
        players[1].score
    );

    EXPECT_EQ(
        -100,
        players[2
        ].score
    );

    //test winner
    EXPECT_EQ(
        0,
        gm.final_winner(players)
    );
}