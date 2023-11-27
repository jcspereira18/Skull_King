
#include "../include/game.h"

void Game::game_play(){

    std::string player_name;
    int win_pos;

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
        print_players(players, i);

    }  

    //bet_round();

    print_bet(players);
    
    for( int j= 0; j < ROUNDS; j++){
        for(int i = 0; i < MAX_PLAYERS; i++){
            print_players(players, i);
            Player* player1 = &players[i];
            play_card(player1, i);
            print_cards_on_table();
        }

        win_pos=checkwin(cards_on_table, color);
        players = order_players(win_pos, players);

        cards_on_table.clear();
        color = -1;
    } 

    players=bet_points(players);

    //the final winner
    final_winner(players);
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

    //cout << "Max: " << max << endl;
    //cout << "Color: " << color << endl;
   
    cards_on_table.push_back(player->hand[index - 1]);

    player->pop_card(index - 1);
   
  
}

void Game::bet_round(){
    cout << endl;
    int bet;
    for( int i = 0; i < MAX_PLAYERS; i++){
        while (true)
        {
            cout << "Enter your bet: ";
            cin >> bet;
            if (cin.fail())
                cerr << "Input Failure";
            else if (bet < 0 || bet > 10)
                std::cout << "Invalid bet!\n";
            else{
                players[i].bet = bet;
                break;
            }
        }
    }
}

void Game::print_bet(vector<Player> players){
    for( int i = 0; i < MAX_PLAYERS; i++){
        cout << "Player " << players[i].name << " bet: " << players[i].bet << endl;
    }
}

void Game::print_players(std::vector<Player> players, int i){
   
        cout << endl;
        cout << "Player " << players[i].name << endl;
        cout << PrintCard2(players[i].hand) << endl;
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
    }
    if(player->hand[index-1].color == red || player->hand[index-1].color== blue || player->hand[index-1].color == yellow || player->hand[index-1].color == black){  
        color = player->hand[index-1].color;
        max = player->hand[index-1].value;
    }
}

bool Game::check_color(Player* player, int index){
  
    if ( player->hand[index-1].color != color  &&  player->hand[index-1].color != white ){
        for ( int i = 0; i < player->hand.size(); i++){
            if ( player->hand[i].color == color)
                return false;
        }
    }
    return true;
}

int Game::checkwin(vector <Card> cards, int color){
   
    int pos = 0;
    special_points = 0;

    for(int i = 0; i < cards.size(); i++){
        if( cards[i].color == color){
            //cout << "Color " << cards[i].color << endl;
            if( max <= cards[i].value){
                max = cards[i].value;
                pos = i;
                //cout << "Max " << max << endl;
                //cout << "Pos " << pos << endl;
            }
        }
        else if( cards[i].color == black && flag == 0)
            pos = i;
        
        else if( cards[i].color == white ){
            if( cards[i].value == 14)
                pos = pos;

            else if( cards[i].value == 15){
                if(skull != -1){
                    pos = i;
                    special_points = 1;              
                }
                
                else if( max < cards[i].value){
                    max = cards[i].value;
                    pos = i;
                    mermaid = pos;
                    flag = 1;
                }
            }

            else if( cards[i].value == 16){
                if(skull != -1){
                    special_points = 3;
                }
                if( max < cards[i].value){
                    max = cards[i].value;
                    pos = i;
                    special_points = 2;
                    flag = 1;
                }
            }

            else if ( cards[i].value == 17){
                if(mermaid != -1){
                    pos = mermaid;
                    special_points = 1;
                }
                else if( max < cards[i].value){
                    max = cards[i].value;
                    pos = i;
                    skull = pos;
                    flag = 1;
                    if(special_points == 2)
                        special_points = 3;
                }
            }
        }
    }

    flag = 0;
    max = 0;
    mermaid = -1;
    skull = -1;
    return pos;
}

vector<Player> Game::order_players(int win_pos, vector<Player> players){

    players[win_pos].points += 1;

    if(special_points == 1)
        players[win_pos].score += 50;
    if(special_points == 3)
        players[win_pos].score += 30;


    cout << "Player " << players[win_pos].name<< " win"<<endl;

    for(int i = 0; i < win_pos; i++){
        players.push_back(players[i]);
    }

    players.erase(players.begin(), players.begin() + win_pos);

    return players;

//    //int n_pirates = special_points - 1;
////
//    //if(special_points > 3)
//    //    players[win_pos].points += 30;
//  //
//    //else 
//        players[win_pos].points += 1;

//    //cout << "Ordem: " << endl;
//    //for (int i = 0; i < players.size(); i++)
//    //    cout << players[i].name << " ";
//    //cout << endl;
}

vector<Player> Game::bet_points(vector<Player> players){
    cout<< endl;
    for(int i = 0; i < players.size(); i++){
        cout << "Player " << players[i].name << " bet " << players[i].bet << " points: " << players[i].points << endl;
        if( players[i].bet == players[i].points )
            if( players[i].bet == 0 )
                players[i].score += 100; 
            else    
                players[i].score += 20 * players[i].bet;
           
        else if( players[i].bet != players[i].points )
            if( players[i].bet == 0 )
                players[i].score += -100;
            else           
                players[i].score += -10 * abs(players[i].points-players[i].bet);
    }
    return players;
}

int Game::final_winner(vector<Player> players){
    cout << endl;
    int max = players[0].score;
    int pos = 0;
    for(int i = 0; i < players.size(); i++){
        cout << "Player " << players[i].name << " points: " << players[i].score << endl;
        if( max < players[i].score){
            max = players[i].score;
            pos = i;
        }
    }

    cout << "The winner is Player " << players[pos].name << " with " << players[pos].score << " points"<< endl;

    return pos;

}