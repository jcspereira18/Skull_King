#ifndef CARD
#define CARD

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

enum Colors {red, blue, yellow, black, white};

enum Numbers {one=1, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen};


class Card{
    //private:
    public:
        Colors color;
        Numbers number;
        int value;

        Card();
        Card(Colors c, Numbers n);
        
        void PrintValue();
        void Printcolor();
        void PrintCard();
};

string PrintCard2(const vector<Card>& cards);

#endif