
#include "../include/game.h"

void Game::game_play(){

    std::string player_name;

    cards_deck.SetupCards();
    cards_deck.shuffle();

    for(int i = 0; i < 4; i++){
        cout << endl;
        std::cout << "Enter your name: ";
        std::cin >> player_name;
        if (std::cin.fail())
            std::cerr << "Input Failure";

        players.push_back(Player(player_name, cards_deck.DealCards(10)));
        //cards_deck.PrintHand();
        print_players(players, i);
    }  
    
    for(int i = 0; i < 4; i++){
        print_players(players, i);
        Player* player1 = &players[i];
        play_card(player1);
        print_players(players, i);
    }
 
    for(int i = 0; i < 4; i++){
        cout << "Player " << players[i].name << ": ";
        cout << cards_on_table[i].value << " " << cards_on_table[i].color << endl;
    }
}



void Game::play_card(Player* player){
    int index;

    while (true)
    {    
        std::cout << "Enter card index " << '(' << "1 - " << player->hand.size() << ')' << ": ";
        std::cin >> index;
        if (std::cin.fail())
            std::cerr << "Input Failure";
        if (index <= 0 || index > player->hand.size()){
            std::cout << "Invalid index!\n";
        }
        //else if (!can_play_card(player->cards[index - 1], top_card))
        //    std::cout << "Can not play " << player->cards[index - 1] << "!\n";
        else
            break;
    }

    //Card card = player->push_card(index - 1);
    cards_on_table.push_back(player->hand[index - 1]);

    //cout << "Card: " << cards_on_table[0].value << " " << cards_on_table[0].color << endl;
    
    //cout << "Card: " << card.value << " " << card.color << endl;
    player->pop_card(index - 1);

    //std::cout << *player << " plays " << card << '\n';
  
}

void Game::print_players(std::vector<Player> players, int i){
    //for(int i = 0; i < players.size(); i++){
    
        cout << endl;
        cout << "Player " << players[i].name << endl;
    
        //for(int j = 0; j < players[i].hand.size(); j++)
        //    players[i].hand[j].PrintCard();
        cout << PrintCard2(players[i].hand) << endl;
    //}
}
