#include "../include/game.h"
#include <gtest/gtest.h>

Game game_s;

TEST(Test_score, SCORE){
    cout << "SCORE" << endl;
    
    vector<Card> test_p1;
    vector<Card> test_p2;
    vector<Card> test_p3;

    vector<Player> players;
    vector<Card> cards_table;

    for (int i = 0; i < 3; i++){
        test_p1.push_back(Card());
        test_p2.push_back(Card());
        test_p3.push_back(Card());
    }
    

    test_p1[0].color = red;
    test_p1[0].value = 7;
    test_p1[1].color = white;
    test_p1[1].value = 17;
   

    test_p2[0].color = white;
    test_p2[0].value = 15;
    test_p2[1].color = yellow;
    test_p2[1].value = 10;

    
    test_p3[0].color = white;
    test_p3[0].value = 17;
    test_p3[1].color = white;
    test_p3[1].value = 16;


    players.push_back(Player("player 1", test_p1));
    players.push_back(Player("player 2", test_p2));
    players.push_back(Player("player 3", test_p3));

    //Sereia e Skull king - 50 pontos 
    for (int i = 0; i < 3; i++)
        cards_table.push_back( players[i].hand[0] );


    players = game_s.order_players(game_s.checkwin(cards_table, red), players); 

    EXPECT_EQ(
        50,
        players[0].score
    );
    cards_table.clear();

    //Pirata e Skull king - 30 pontos 
    for (int i = 0; i < 3; i++)
        cards_table.push_back( players[i].hand[1] );


    players = game_s.order_players(game_s.checkwin(cards_table, yellow), players); 

    for(int i = 0; i < players.size(); i++)
        cout << players[i].name << " " << players[i].score << endl;

    EXPECT_EQ(
        30,
        players[0].score
    );

}