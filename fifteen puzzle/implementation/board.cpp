
#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <conio.h>
#include <string>
#include <cstdlib>      // std::rand, std::srand

using std::cout; using std::string;
using std::endl; using std::cin;
using std::__cxx11::to_string;

#include "../headers/board.h"

constexpr auto UP = 119;
constexpr auto DOWN = 115;
constexpr auto RIGHT = 100;
constexpr auto LEFT = 97;
constexpr auto ESC = 27;


Board::Board(){
    player = new Player();
    cache = new int[2];
    num_movements = 0;
    for(int i = 0; i < 15; i++){
        if(i < 9){
            unsorted_board.push_back("0" + to_string(i + 1));
            }
        else{
            unsorted_board.push_back(to_string(i + 1 ));
        }
    }
    unsorted_board.push_back(player->getAvatar());
    srand ( unsigned ( time(0) ) );
    random_shuffle(unsorted_board.begin(), unsorted_board.end());

    int aux = 0;
    for(int i = 0; i < 4; i++ ){
        for (int j = 0; j < 4; j++){
            if(aux < 9){
                solved[i][j] = "0" + to_string(aux + 1);
            }
            else{
                solved[i][j] = to_string(aux + 1);
            }
            board[i][j] = unsorted_board[aux];
            if(board[i][j] == "  "){
                player->pos->setX(j);
                player->pos->setY(i);
            }
            aux++;
        }
    }

    solved[3][3] = player->getAvatar();
    cache[0] = player->pos->getX();
    cache[1] = player->pos->getY();
}

Board::~Board(){

}

bool Board::game_over(){
    if(!(num_movements%500) && num_movements){
        char temp;
        cout<<num_movements<<" attempts were given\n";
        cout<<"This puzzle could probably has no solution\n";
        cout<<"Do you want to keep trying?(y/n): ";
        cin>>temp;
        while(!(temp == 'y' || temp == 'n')){
            system("cls");
            cout<<"Please enter a valid option\n";
            cout<<"Do you want to keep trying?(y/n): ";
            cin>>temp;
        }
        if(temp == 'n'){
            cout<<" \nGame over!\n";
            return true;
        }
        else{
            printBoard();
            return false;
        }
    }
    for(int i = 0 ; i < 4; i++ ){
        for(int j = 0; j < 4; j++){
            if(!(board[i][j] == solved[i][j])){
                return false;
            }
        }
    }

    cout<<"Puzzle done! Congratulations!\n";
    cout<<"The number of movements made was: "<<num_movements<<"\n";
    return true;
}

bool Board::movement(){
    char key;

    cache[0] = player->pos->getX();
    cache[1] = player->pos->getY();

    key = _getch();  
    if( key == UP) {
        return player->pos->move_y( 1 );
    }
    if (key == DOWN){
        return player->pos->move_y( 0 );
    }
    if( key == LEFT) {
        return player->pos->move_x( 1 );
    }
    if (key == RIGHT){
        return player->pos->move_x( 0 );
    }
    return false;
}


void Board::printBoard(){
    cout<<"\n ---------------------\n";
    for(int i = 0; i < 4; i++){
        cout<<" |";
        for(int j = 0; j < 4; j++){
            cout<<" "<<board[i][j]<<" |";
        }
        cout<<"\n ---------------------\n";
    }
}

void Board::update(){
    char cur_x = player->pos->getX(), cur_y = player->pos->getY();
    board[cache[1]][cache[0]] = board[cur_y][cur_x];
    board[cur_y][cur_x] = player->getAvatar();
    num_movements++;
    cout<<"\nNumber of movements: "<<num_movements<<"\n";
    
}