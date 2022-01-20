#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "../headers/computer.h"


Computer::Computer(char _avatar = 'O') : Player{ _avatar } { } 

Computer::~Computer(){

}

int Computer::ask_for_movement(int* valid_movements){
    int m_board_size = sizeof(valid_movements)/sizeof(valid_movements[0]);
    srand ( unsigned ( time(0) ) );
    int _movement = rand() % m_board_size;
    add_movement(_movement);
    increment_num_movements();
    return _movement;
}