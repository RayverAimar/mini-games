#include "../headers/playhandler.h"

PlayHandler::PlayHandler(int _pos){ //Se le puede pasar el tablero y decidir en que element aparecerá
    m_pos = _pos;
}
PlayHandler::~PlayHandler(){

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
