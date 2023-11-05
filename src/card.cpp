
#include "card.h"

Card::Card(){
    color = red;
    number = one;
}

Card::Card(Colors c, Numbers n){
    this->color = c;
    this->number = n;
}

void Card::PrintCard(){
    PrintValue();
    Printcolor();
    std::cout << std::endl;
}

string PrintCard2(const vector<Card>& cards){

    int len_cards = cards.size();
    string str_cards = "[";
    for (int i = 0; i < len_cards; ++i)
    {
        str_cards += to_string(cards[i].value);
        if (i != len_cards - 1)
            str_cards += ", ";
    }
    str_cards += "]";
    return str_cards;
}

void Card::PrintValue(){
    if(value == 14)
        std::cout << "Escape";
    else if (value == 15)
        std::cout << "Mermaid";
    else if (value == 16)
        std::cout << "Pirate";
    else if(value == 17)
        std::cout << "Skull King";
    else
        std::cout << value ;
}

void Card::Printcolor(){
    if(color == red)
        std::cout << " red";
    else if (color == blue)
        std::cout << " blue";
    else if (color == yellow)
        std::cout << " yellow";
    else if (color == black)
        std::cout << " black";
    else
        std::cout << " ";
}
