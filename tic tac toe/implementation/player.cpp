#include "../headers/player.h"

Player::Player(char _avatar){
    m_movements = new int[5];
    m_avatar = _avatar;
    turn = false;
}
Player::~Player(){
    delete m_movements, num_movements;
}

char Player::getAvatar(){
    return m_avatar;
}

int Player::get_num_movements(){
    return num_movements;
}

int* Player::get_m_movements(){
    return m_movements;
}

void Player::add_movement(int _movement){
    m_movements[num_movements] = _movement;
}

void Player::increment_num_movements(){
    num_movements++;
}

void Player::shift_change(){
    turn = !turn;
}
