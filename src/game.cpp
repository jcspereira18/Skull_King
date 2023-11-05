
#include "game.h"

void Game::game_play(){

    std::string player_name;

    cards_deck.SetupCards();
    cards_deck.shuffle();

    for(int i = 0; i < 4; i++){
        std::cout << "Enter your name: ";
        std::cin >> player_name;
        if (std::cin.fail())
            std::cerr << "Input Failure";

        players.push_back(Player(player_name, cards_deck.DealCards(10)));
        //cards_deck.PrintHand();
    }
}

void Game::print_players(){
    for(int i = 0; i < players.size(); i++){
        std::cout << players[i].name << std::endl;
        for(int j = 0; j < players[i].hand.size(); j++)
            players[i].hand[j].PrintCard();
    }
    std::cout << std::endl;
}
