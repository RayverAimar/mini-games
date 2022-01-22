#include "../headers/player.h"

Player::Player(char _avatar){
    m_movements = new int[5];
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
    m_turn = !m_turn;
}

bool Player::get_turn(){
    return m_turn;
}