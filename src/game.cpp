
#include "../include/game.h"

void Game::game_play(){

    std::string player_name;

    cards_deck.SetupCards();
    cards_deck.shuffle();
    //cards_deck.PrintDeck();

    for(int i = 0; i < MAX_PLAYERS; i++){
        cout << endl;
        std::cout << "Enter your name: ";
        std::cin >> player_name;
        if (std::cin.fail())
            std::cerr << "Input Failure";

        players.push_back(Player(player_name, cards_deck.DealCards(10)));
        //cards_deck.PrintHand();
        print_players(players, i);
    }  
    
    for( int j= 0; j < ROUNDS; j++){
        for(int i = 0; i < MAX_PLAYERS; i++){
            print_players(players, i);
            Player* player1 = &players[i];
            play_card(player1, i);
            
            print_cards_on_table();
            //print_players(players, i);
        }
    
        checkwin();
        cards_on_table.clear();
        flag = 0;
        max = 0;
        color = -1;
    } 

    for(int i = 0; i < players.size(); i++)
        cout << "Player " << players[i].name << " points: " << players[i].points << endl;
    
    //the final winner
    final_winner();
}



void Game::play_card(Player* player, int i){
    int index;

    while (true)
    {    
        std::cout << "Enter card index " << '(' << "1 - " << player->hand.size() << ')' << ": ";
        std::cin >> index;
        if (std::cin.fail()){
            std::cerr << "Input Failure";
            break;
        }     
        
        if (index <= 0 || index > player->hand.size())
            std::cout << "Invalid index!\n";

        else if (!check_color(player, index) && i!=0)
            std::cout << "Can't play " << endl;
        else{
            if(color == -1 )
                color_round(player, index);
            break;
        }
    }

    cout << "Max: " << max << endl;
    cout << "Color: " << color << endl;
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

void Game::print_cards_on_table(){
    cout << endl;
    for(int i = 0; i < cards_on_table.size(); i++){
        cout << "Player " << players[i].name << ": ";
        cout << cards_on_table[i].value << " " << cards_on_table[i].color << endl;
    }
}

void Game::color_round(Player* player, int index){

        if(player->hand[index-1].value == 15 || player->hand[index-1].value == 16 || player->hand[index-1].value == 17){
            color = -2;
            
            //break;
        }
    //for(int i = 0; i < player->hand.size(); i++){
        if(player->hand[index-1].color == red || player->hand[index-1].color== blue || player->hand[index-1].color == yellow || player->hand[index-1].color == black){  
            color = player->hand[index-1].color;
            max = player->hand[index-1].value;
            //break;
        }
    //}


}

bool Game::check_color(Player* player, int index){
  
    //for( int i = 0; i < player->hand.size(); i++){
       if ( player->hand[index-1].color != color  &&  player->hand[index-1].color != white ) 
            for ( int i = 0; i < player->hand.size(); i++){
                if ( player->hand[i].color == color)
                    return false;
            }

   //}
    return true;
}

void Game::checkwin(){

    int pos = 0;

    for(int i = 0; i < cards_on_table.size(); i++){
        if( cards_on_table[i].color == color){
            if( max <= cards_on_table[i].value){
                max = cards_on_table[i].value;
                pos = i;
            }
        }

        else if( cards_on_table[i].color == black && flag == 0){
                //cout << "Passei aqui" << endl;
                pos = i;
        }
        
        else if( cards_on_table[i].color == white ){
            if( cards_on_table[i].value == 14)
                pos = pos;

            else if( cards_on_table[i].value == 15){
                if( max < cards_on_table[i].value){
                    max = cards_on_table[i].value;
                    pos = i;
                    flag = 1;
                }
            }

            else if( cards_on_table[i].value == 16){
                if( max < cards_on_table[i].value){
                    max = cards_on_table[i].value;
                    pos = i;
                    flag = 1;
                }
            }

            else if ( cards_on_table[i].value == 17){
                if( max < cards_on_table[i].value){
                    max = cards_on_table[i].value;
                    pos = i;
                    flag = 1;
                }
            }
        }
    }
    

    //cout << "Max: " << max << endl;
    cout << "Player " << players[pos].name<< " win"<<endl;
    
    players[pos].points += 1;

    cout<< "Pos: " << pos << endl;
    for(int i = 0; i < pos; i++){
        players.push_back(players[i]);
        //cout << "sdskf " << players[i].name << endl;
    }
    players.erase(players.begin(), players.begin() + pos);

    cout << "Ordem: " << endl;
    for (int i = 0; i < players.size(); i++)
        cout << players[i].name << " ";
    cout << endl;
}

void Game::final_winner(){

    int max = players[0].points;
    int pos = 0;
    for(int i = 0; i < players.size(); i++){
        if( max < players[i].points)
            pos = i;
    }

    cout << "The winner is Player " << players[pos].name << " with " << players[pos].points << " points"<< endl;
}