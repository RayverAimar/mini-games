#include "headers/game.h"

int main(){
    int opt;
    Game game;
    do{
        cout<<"1. Human vs PC mode\n2. Human vs Human mode\n";
        cin>>opt;
    }while(opt != 1 && opt != 2);
    if(opt == 1){
        game.PvsPC();
    }
    else{
        game.PvsP();
    }
    
}