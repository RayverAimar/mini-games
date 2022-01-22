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
    Game();
    ~Game();
    void player_movement(); //Re - pensar la función que me permita a mi elegir mi casilla y al bot randomnear alguna
    void computer_movement();
    void run();
    void updateBoard(char _avatar, int pos);
    void printBoard();
    void printBoard(char _PH_avatar);
    bool game_over();
    bool move_play_handler();

};




#endif