#ifndef _GAME_H_
#define _GAME_H_


#include <iostream>
#include <conio.h>
#include "../headers/player.h"
#include "../headers/playhandler.h"
#include "../headers/computer.h"

using std::cout; using std::endl;

class Game{
    char* m_board;
    int n_turn;
public:

    Player *m_player;
    Computer *m_computer;
    PlayHandler *m_playhandler;

    //Constructors & Destructor
    Game();
    ~Game();

    //Getters
    bool game_over();

    //Setters
    void set_PH_valid_position(); 

    //Auxiliar Functions
    void computer_movement();
    void printBoard();
    void move_play_handler();
    void results();

};

#endif