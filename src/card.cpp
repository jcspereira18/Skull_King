
#include "../include/card.h"

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

string PrintCard2(const vector<Card>& cards){

    string str_cards = "[";
    for (int i = 0; i < cards.size(); ++i)
    {
        str_cards += to_string(cards[i].value);
        str_cards += " ";
        str_cards += to_string(cards[i].color);
        if (i != cards.size() - 1)
            str_cards += ", ";
    }
    str_cards += "]";
    return str_cards;
}

