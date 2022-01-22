#include <iostream>
#include "../headers/playhandler.h"

using std::cout;

PlayHandler::PlayHandler(int _pos){ //Se le puede pasar el tablero y decidir en que element aparecerá
    m_pos = _pos;
    m_last_pos = _pos;
    m_avatar = '#';
    activity = true;
}
PlayHandler::~PlayHandler(){

}


void PlayHandler::move_pos(int _to_move, char* m_board){
    bool valid_move = false;
    m_last_pos = m_pos;
    do{
        
        m_pos += _to_move;
        if(m_pos < 0 ){
            m_pos = 8;
        }
        m_pos = m_pos % 9;
    }while(m_board[m_pos] != ' ');
}


int PlayHandler::get_pos(){ 
    return m_pos;
}

int PlayHandler::get_last_pos(){
    return m_last_pos;
}

bool PlayHandler::get_activity(){
    return activity;
}

char PlayHandler::get_avatar(){
    return m_avatar;
}

void PlayHandler::set_pos(int _pos){
    m_pos = _pos;
    m_last_pos = _pos;
}