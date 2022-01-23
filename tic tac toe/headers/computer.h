#ifndef _COMPUTER_H_
#define _COMPUTER_H_


#include "player.h"

class Computer: public Player{
public:
    //Constructors & Destructor
    Computer(char _avatar);
    ~Computer();

    //Setters (NULL)

    //Getters
    int ask_for_movement(int _size);

    //Auxiliar Functions (NULL)

};



#endif