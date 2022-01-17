#include <iostream>
#include "headers/board.h"

int main(){

    Board board;
    system("cls");
    board.printBoard();
    std::cout<<"\nPress w a s d to move. . . ";
    while(!board.game_over()){
        if(board.movement()){
            system("cls");
            board.update();
            board.printBoard();
        }
    }
}
