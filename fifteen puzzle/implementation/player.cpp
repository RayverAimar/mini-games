#include "../headers/player.h"


Player::Player(){
    pos = new Point2D(0,0);
    m_avatar = "  ";
}

Player::~Player(){

}

string Player::getAvatar(){ return m_avatar; }