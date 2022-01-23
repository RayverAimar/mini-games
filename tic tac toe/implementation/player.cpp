#include "../headers/player.h"
#include <iostream>


Player::Player(char _avatar){
    m_movements = new int[5];
    for(int i = 0; i < 0; i++){
        m_movements[i] = -1;
    }
    m_avatar = _avatar;
    m_turn = false;
    num_movements = 0;
}
Player::~Player(){
    delete m_movements;
}

char Player::getAvatar(){
    return m_avatar;
}

int Player::get_num_movements(){
    return num_movements;
}

void Player::add_movement(int _movement){
    m_movements[num_movements] = _movement;
    num_movements++;
}

void Player::shift_change(){
    m_turn = !m_turn;
}

bool Player::get_turn(){
    return m_turn;
}
void Player::print_moves(){
    for(int i = 0; i < num_movements; i++){
        std::cout << m_movements[i] << " ";
    }
    std::cout << std::endl;
}

bool Player::find(int _board_position){
    for(int i = 0; i < num_movements; i++){
        if(m_movements[i] == _board_position){
            return true;
        }
    }
    return false;
}

bool Player::won(){
    if(find(0) && find(1) && find(2)){ //Horizontales
        return true;
    }
    if(find(3) && find(4) && find(5)){
        return true;
    }
    if(find(6) && find(7) && find(8)){
        return true;
    }
    if(find(0) && find(3) && find(6)){ //Verticales
        return true;
    }
    if(find(1) && find(4) && find(7)){
        return true;
    }
    if(find(2) && find(5) && find(8)){
        return true;
    }
    if(find(0) && find(4) && find(8)){ //Diagonales
        return true;
    }
    if(find(2) && find(4) && find(6)){
        return true;
    }
    return false;
}

