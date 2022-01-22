
#include "../headers/game.h"


constexpr auto UP = 119;
constexpr auto DOWN = 115;
constexpr auto RIGHT = 100;
constexpr auto LEFT = 97;
constexpr auto ESC = 27;

Game::Game(){
    m_playhandler = new PlayHandler();
    m_computer = new Computer('O');
    m_player = new Player('X');
    m_board = new char[9];
    for(int i = 0; i < 9; i++){
        m_board[i] = ' ';
    }
}

Game::~Game(){
    delete m_player, m_board, m_computer;
}

void Game::computer_movement(){
    int* valid_movements = new int[9];
    int counter{0};
    for(int i = 0; i < 9; i++){
        if(m_board[i] == ' '){
            valid_movements[counter] = i;
            counter++;
        }
    }
    int computer_move = m_computer->ask_for_movement(valid_movements, ++counter);
    m_board[valid_movements[computer_move]] = m_computer->getAvatar();
    
}

void Game::updateBoard(char _avatar, int pos){
    m_board[pos - 1] = _avatar; 
}

void Game::printBoard(){
    //system("cls");
    if(m_player->get_turn()){
        m_board[m_playhandler->get_last_pos()] = ' ';
        m_board[m_playhandler->get_pos()] = m_playhandler->get_avatar();
    }
    for(int i = 0; i < 9; i++){
        if(!(i%3)){
            cout<<"\n -------------\n";
            cout<<" |";
        }
        cout<<" "<<m_board[i]<<" |";
    }    
    cout<<"\n -------------\n\n";
}

bool Game::move_play_handler(){
    char key;

    while(key != RIGHT && key != LEFT && key != 13){
        key = _getch();
    }
    if(key == RIGHT){
        m_playhandler->move_pos(1);
        cout<<"Presiono RIGHT"<<endl;
    }
    if(key == LEFT){
        cout<<"Presiono LEFT"<<endl;
        m_playhandler->move_pos(-1);
    }
    if(key == 13){
        cout<<"Presiono enter"<<endl;
        m_player->shift_change();
        return false;
    }
    return true;

}

void Game::printBoard(char _PH_avatar){
    system("cls");
    if(m_player->get_turn()){
        m_board[m_playhandler->get_pos()] = m_playhandler->get_avatar();
    }
    for(int i = 0; i < 9; i++){
        if(!(i%3)){
            cout<<"\n -------------\n";
            cout<<" |";
        }
        cout<<" "<<m_board[i]<<" |";
    }    
    cout<<"\n -------------\n\n";
}