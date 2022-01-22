#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "../headers/computer.h"


Computer::Computer(char _avatar = 'O') : Player{ _avatar } { } 

Computer::~Computer(){

}

int Computer::ask_for_movement(int* valid_movements, int _size){
    srand ( unsigned ( time(0) ) );
    int _movement = rand() % _size;
    add_movement(_movement);
    increment_num_movements();
    return _movement;
}