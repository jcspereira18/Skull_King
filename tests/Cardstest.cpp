#include "../include/Example.hpp"

#include "../include/game.h"
#include "../include/card.h"

#include <gtest/gtest.h>

Game g;
Card c;

TEST(Tests_cards, cards){
    
    cout << "CARD" << endl;
    vector <Card> card_test;
    int check_color;   
  
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
   
   check_color = card_test[0].color;
    
    //Red cards
    cout << "Test red cards" << endl;
    EXPECT_EQ(
        0,
        g.checkwin(card_test, check_color)
    );

    card_test[0].color = blue;  
    card_test[0].value = 2;
    card_test[1].color = blue;
    card_test[1].value = 13;
    card_test[2].color = blue;
    card_test[2].value = 5;
    
    check_color = card_test[0].color;
    
    //Blue cards
    cout << "Test blue cards" << endl;
    EXPECT_EQ(
        1,
        g.checkwin(card_test, check_color)
    );

    card_test[0].color = yellow;
    card_test[0].value = 6;
    card_test[1].color = yellow;
    card_test[1].value = 7;
    card_test[2].color = black;
    card_test[2].value = 2;
    check_color = card_test[0].color;

    cout << "Test one black card" << endl;
    EXPECT_EQ(
        2,
        g.checkwin(card_test, check_color)
    );

    card_test[0].color = white;
    card_test[0].value = 16; //pirata
    card_test[1].color = white;
    card_test[1].value = 14; //bandeira
    card_test[2].color = black;
    card_test[2].value = 2;
    check_color = -1;

    cout << "Test pirate and escape cards" << endl;
    EXPECT_EQ(
        0,
        g.checkwin(card_test, check_color)
    );

    
    card_test[0].color = blue;
    card_test[0].value = 4;
    card_test[1].color = blue;
    card_test[1].value = 10;
    card_test[2].color = white;
    card_test[2].value = 15; //sereia
    check_color = card_test[0].color;

    cout << "Test mermaid card" << endl;
    EXPECT_EQ(
        2,
        g.checkwin(card_test, check_color)
    );


    card_test[0].color = red;
    card_test[0].value = 4;
    card_test[1].color = black;
    card_test[1].value = 2;
    card_test[2].color = red;
    card_test[2].value = 10;
    card_test[3].color = white;
    card_test[3].value = 17; //Skull King
    check_color = card_test[0].color;

    cout << "Test Skull King card" << endl;
    EXPECT_EQ(
        3,
        g.checkwin(card_test, check_color)
    );

    card_test[0].color = white;
    card_test[0].value = 15; //sereia
    card_test[1].color = black;
    card_test[1].value = 2;
    card_test[2].color = red;
    card_test[2].value = 10;
    card_test[3].color = white;
    card_test[3].value = 17; //Skull King
    check_color = -1;

    cout << "Test Skull King and mermaid card" << endl;
    EXPECT_EQ(
        0,
        g.checkwin(card_test, check_color)
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