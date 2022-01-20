#ifndef _GAME_H_
#define _GAME_H_


#include <iostream>
#include "../headers/player.h"

using std::cout; using std::endl;


class Game{
    Player *m_player, *m_computer;
    char* m_board;
    int n_turn;
public:
    Game();
    ~Game();
    void player_movement(); //Re - pensar la función que me permita a mi elegir mi casilla y al bot randomnear alguna
    void computer_movement();
    void run();
    void printBoard();
    bool game_over();

};


#endif