#include "headers/game.h"

constexpr auto UP = 119;
constexpr auto DOWN = 115;
constexpr auto RIGHT = 100;
constexpr auto LEFT = 97;
constexpr auto ESC = 27;

int* swap_array(int* m_movements){
    return m_movements;
}

int main(){
    

    //char key;
    //while(key!= 13){
    //    key = _getch();
    //}
    Game game;
    game.printBoard();
    game.m_player->shift_change();
    while(true){
        system("cls");
        game.printBoard();
        if(game.m_player->get_turn()){
            game.move_play_handler();
        }
        else{
            game.computer_movement();
            game.m_player->shift_change();
        }
        //cout<<"\n"<<game.m_playhandler->get_pos()<<"\n";
    }



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