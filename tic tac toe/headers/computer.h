#ifndef _COMPUTER_H_
#define _COMPUTER_H_


#include "player.h"

class Computer: public Player{
public:
    Computer(char _avatar);
    ~Computer();
    int ask_for_movement(int _size);
};



#endif