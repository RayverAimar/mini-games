#include <iostream>

using namespace std;

int board[4][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};

void printBoard(){
    cout<<"\n ---------------------\n";
    for(int i = 0; i < 4; i++){
        cout<<" |";
        for(int j = 0; j < 4; j++){
            if(board[i][j] > 9){
                cout<<" "<<board[i][j]<<" |";
            }
            else{
                cout<<"  "<<board[i][j]<<" |";
            }
        }
        cout<<"\n ---------------------\n";
    }
}

int main(){
    printBoard();
}