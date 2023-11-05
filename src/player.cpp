
#include "player.h"

Player::Player(std::string name, std::vector<Card> hand):
   name(name), hand(hand){}


void Player::set_name(std::string name){
    this->name = name;
}

void Player::set_points(int points){
    this->points = points;
}

