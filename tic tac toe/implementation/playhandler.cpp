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


bool PlayHandler::move_pos(int _to_move){
    m_last_pos = m_pos;
    int cache = m_pos;
    m_pos += _to_move;
    m_pos = m_pos % 9;
    if(m_pos<0 || m_pos>8){
        m_pos = cache;
        return false;
    }
    return true;
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