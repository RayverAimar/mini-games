
#include "../headers/game.h"


constexpr auto UP = 119;
constexpr auto DOWN = 115;
constexpr auto RIGHT = 100;
constexpr auto LEFT = 97;
constexpr auto ESC = 27;

Game::Game(){
    m_computer = new Player('O');
    m_player = new Player('X');
    m_board = new char[9];
    for(int i = 0; i < 9; i++){
        m_board[i] = ' ';
    }
}

Game::~Game(){
    delete m_player, m_board, m_computer;
}

void Game::printBoard(){
    
    for(int i = 0; i < 9; i++){
        if(!(i%3)){
            cout<<"\n -------------\n";
            cout<<" |";
        }
        cout<<" "<<m_board[i]<<" |";
    }    
    cout<<"\n -------------\n\n";
}