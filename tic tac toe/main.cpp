#include "headers/game.h"


int* swap_array(int* m_movements){
    return m_movements;
}

int main(){
    
    Game game;
    game.printBoard();
    //Necesito una función que me permita navegar por el tablero hasta que presione enter y capturar la ultima posicion

    /**
     * while(!game.game_over()){
     * 
     *      if(player.turn()){
     *          pos = PlayHandler::get_valid_movement(); //Navegar por el tablero entre posiciones validas hasta capturar enter
     *          game.updateBoard(player.get_avatar(),player.ask_movement());
     *      }
     *      else{
     *          game.updateBoard(computer.get_avatar(), computer.ask_for_movement(game.get_valid_movements())); //player.turn = 1;
     *      }
     *      game.printBoard();
     * 
     * }
     * 
     * 
     */
    /**
    int numeros[10] = {1,2,3,4,5,6,7,8,9};
    
    char key;

    while(!(key == 13)){
        key = _getch();
    }*/

}