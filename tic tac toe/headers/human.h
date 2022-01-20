#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "player.h"

class Human : public Player{

public:
    Human(char _avatar);
    ~Human();
    void ask_for_movement();
};





#endif