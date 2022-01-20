#include <iostream>
#include "../headers/playhandler.h"

using std::cout;

PlayHandler::PlayHandler(int _pos){ //Se le puede pasar el tablero y decidir en que element aparecerá
    m_pos = _pos;
    m_avatar = '#';
}
PlayHandler::~PlayHandler(){

}

void PlayHandler::browse(int* &m_board){

}

bool PlayHandler::move_pos(int _to_move){
    int cache = m_pos;
    m_pos += _to_move;
    if(m_pos<0 || m_pos>8){
        m_pos = cache;
        return false;
    }
    return true;
}

bool PlayHandler::update_pos(int _to_move){
    int cache = m_pos;
    m_pos += _to_move;
    if(m_pos<0 || m_pos>8){
        m_pos = cache;
        return false;
    }
    return true;
}

int PlayHandler::get_pos(){ 
    return m_pos;
}
