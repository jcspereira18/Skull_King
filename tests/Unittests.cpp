#include "../include/Example.hpp"

#include "../include/game.h"
#include "../include/card.h"

#include <gtest/gtest.h>

Game g;
Card c;

//struct ExampleTests 
//    : public ::testing::Test 
//{
//
//    Card c;
//
//   
//};

TEST(ExampleTests, WIN){

    g.cards_deck.SetupCards();
    g.cards_deck.shuffle();

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

TEST(ExampleTests, cards){
    
    cout << "CARD" << endl;
    vector <Card> card_test;

   int max = 0;

    g.cards_deck.SetupCards();
    g.cards_deck.shuffle();

    vector<Player> p;
    for (int i = 0; i < 4; i++)
        p.push_back( Player("player", g.cards_deck.DealCards(10)) );
    
    for (int i = 0; i < 4; i++)
        card_test.push_back(Card());

    card_test[0].color = red;
    card_test[0].value = 7;
    card_test[1].color = red;
    card_test[1].value = 1;
    card_test[2].color = red;
    card_test[2].value = 2;
    card_test[3].color = red;
    card_test[3].value = 3;
    
    int check_color = card_test[0].color;
    
    //Red cards
    EXPECT_EQ(
        0,
        g.checkwin(p, card_test, check_color)
    );

    card_test[0].color = blue;  
    card_test[0].value = 2;
    card_test[1].color = blue;
    card_test[1].value = 13;
    card_test[2].color = blue;
    card_test[2].value = 5;
    
    check_color = card_test[0].color;
    
    //Blue cards
    EXPECT_EQ(
        1,
        g.checkwin(p, card_test, check_color)
    );

    card_test[0].color = yellow;
    card_test[0].value = 6;
    card_test[1].color = yellow;
    card_test[1].value = 7;
    card_test[2].color = black;
    card_test[2].value = 2;
    check_color = card_test[0].color;

    EXPECT_EQ(
        2,
        g.checkwin(p, card_test, check_color)
    );

}

//struct ExampleTests 
//    : public ::testing::Test 
//{
//    int* x;
//
//    int GetX(){
//        return *x;
//    }
//
//    virtual void SetUp() override{
//        fprintf(stderr, "Starting Up\n");
//        x = new int(42);
//    }
//
//    virtual void TearDown() override{
//        fprintf(stderr, "Tearing Down\n");
//        delete x;
//    }
//};
//
//
//TEST_F(ExampleTests, MAC) {
//    //int x = 42;
//    int y = 16;
//    int sum =100;
//    int oldSum = sum;
//    int ex = oldSum + GetX()  * y;
//
//    EXPECT_EQ(
//        ex,
//        MAC(GetX(), y, sum)
//    );
//    EXPECT_EQ(
//        ex,
//        sum
//    );
//}
//
//TEST(ExampleTests2, Square) {
//    int x = 5;
//    int ex = x * x;
//    EXPECT_EQ(
//        ex,
//        Square(x)
//    );
//}