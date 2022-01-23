#include "headers/game.h"

using std::cin;

int main(){
    char opt;
    Game game;
    do{
        cout<<"Do you want to take the first movement? (y/n): "<<endl;
        cin >> opt;    
    }while(opt != 'y' && opt != 'n');
    
    if(opt == 'y')
        game.m_player->shift_change();
    while(!game.game_over()){
        system("cls");
        game.printBoard();
        if(game.m_player->get_turn()){
            game.move_play_handler();
        }
        else{
            game.computer_movement();
            game.m_player->shift_change();
        }
    }
    game.results();
}