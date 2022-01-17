#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

constexpr auto UP = 119;
constexpr auto DOWN = 115;
constexpr auto RIGHT = 100;
constexpr auto LEFT = 97;
constexpr auto ESC = 27;

class Point2D{
    int m_x, m_y;
    
    public:
    //Constructor & Destructor
    Point2D(int x, int y);
    ~Point2D();

    //Setters
    bool move_x(bool mov); //mov = 1, move forward
    bool move_y(bool mov); //mov = 0, move back
    int getX();
    int getY();
    void print_values(){ cout<<m_x<<endl<<m_y<<endl;}

};

Point2D::Point2D(int x, int y): m_x(x), m_y{y}{}

Point2D::~Point2D(){

}

bool Point2D::move_x(bool mov){
    int back_up = m_x;
    if(mov) { m_x++; }
    else { m_x--; }
    if(m_x < 0 || m_x > 3) {
        m_x = back_up; 
        return false;
    }
    return true;
}
bool Point2D::move_y(bool mov){
    int back_up = m_y;
    if(mov) {m_y++;}
    else {m_y--;}
    if(m_y < 0 || m_y > 3) { 
        m_y = back_up;
        return false; }// NO hubo movimiento
    return true; // Sí lo hubo
}

int Point2D::getX(){ return m_x; }

int Point2D::getY(){ return m_y; }

class Player{ 
    string m_avatar;
    public:
    Player();
    ~Player();
    Point2D *pos;
    string getAvatar();
};

Player::Player(){
    pos = new Point2D(3,3);
    m_avatar = "  ";
}

Player::~Player(){

}

string Player::getAvatar(){ return m_avatar; }

class Board{
    Player *player;
    int *cache;
    string board[4][4], solved[4][4];

    public:

    Board();
    ~Board();

    bool game_over();
    bool movement();
    void printBoard();
    void update();
};

Board::Board(){
    player = new Player();
    cache = new int[2];
    cache[0] = player->pos->getX();
    cache[1] = player->pos->getY();
    int aux = 1;
    for(int i = 0; i < 4; i++ ){
        for (int j = 0; j < 4; j++){
            if(aux < 10){
                board[i][j] = "0" + to_string(aux);
                solved[i][j] = "0" + to_string(aux);
            }
            else{
                board[i][j] = to_string(aux);
                solved[i][j] = to_string(aux);
            }
            aux++;
        }
    }
    board[3][3] = player->getAvatar();
    solved[3][3] = player->getAvatar();

}

Board::~Board(){

}

bool Board::game_over(){
    for(int i = 0 ; i < 4; i++ ){
        for(int j = 0; j < 4; j++){
            if(!(board[i][j] == solved[i][j])){
                return false;
            }
        }
    }
    return true;
}

bool Board::movement(){
    char key;

    cache[0] = player->pos->getX();
    cache[1] = player->pos->getY();

    key = _getch();  
    if( key == UP) {
        return player->pos->move_y( 1 );
    }
    if (key == DOWN){
        return player->pos->move_y( 0 );
    }
    if( key == LEFT) {
        return player->pos->move_x( 1 );
    }
    if (key == RIGHT){
        return player->pos->move_x( 0 );
    }
    return false;
}


void Board::printBoard(){
    cout<<"\n ---------------------\n";
    for(int i = 0; i < 4; i++){
        cout<<" |";
        for(int j = 0; j < 4; j++){
            cout<<" "<<board[i][j]<<" |";
        }
        cout<<"\n ---------------------\n";
    }
}

void Board::update(){
    char cur_x = player->pos->getX(), cur_y = player->pos->getY();
    board[cache[1]][cache[0]] = board[cur_y][cur_x];
    board[cur_y][cur_x] = player->getAvatar();
}
int main(){

    Board board;
    board.printBoard();
    board.movement();
    board.update();
    system("cls");
    board.printBoard();
    
    while(!board.game_over()){
        if(board.movement()){
            system("cls");
            board.update();
            board.printBoard();
        }
    }
    /*
    if(!board.game_over()){
        cout<<"No es el final del juego"<<endl;
    }
    else{
        cout<<"Si es el final del juego"<<endl;
    }*/
}
