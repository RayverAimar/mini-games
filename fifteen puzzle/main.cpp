#include <iostream>
#include <conio.h>

using namespace std;

constexpr auto UP = 72;
constexpr auto DOWN = 80;
constexpr auto RIGHT = 77;
constexpr auto LEFT = 75;
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
    cout<<back_up<<endl;
    if(mov) m_x++;
    else m_x--;
    if(m_x < 0 && m_x > 3) m_x = back_up; return false;
    return true;
}
bool Point2D::move_y(bool mov){
    int back_up = m_y;
    if(mov) m_y++;
    else m_y--;
    if(m_y < 0 && m_y > 3) m_y = back_up; return false; // NO hubo movimiento
    return true; // Sí lo hubo
}

int Point2D::getX(){ return m_x; }

int Point2D::getY(){ return m_y; }

class Player{ 
    int m_avatar;
    public:
    Player();
    ~Player();
    Point2D *pos;
    int getAvatar();
};

Player::Player(){
    pos = new Point2D(3,3);
    m_avatar = 0;
}

Player::~Player(){

}

int Player::getAvatar(){ return m_avatar; }

class Board{
    Player *player;
    int *cache;
    int board[4][4];

    public:

    Board();
    ~Board();

    void printBoard();
    bool movement();
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
            board[i][j] = aux;
            aux++;
        }
    }
    board[3][3] = 0;

}

Board::~Board(){

}

bool Board::movement(){
    char key;

    cache[0] = player->pos->getX();
    cache[1] = player->pos->getY();

    key = _getch();
    
    if( key == UP) {
        return player->pos->move_y( 0 );
    }
    if (key == DOWN){
        return player->pos->move_y( 1 );
    }
    if( key == LEFT) {
        return player->pos->move_x( 0 );
    }
    if (key == RIGHT){
        return player->pos->move_x( 1 );
    }
    return false;
}


void Board::printBoard(){
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

void Board::update(){
    int cur_x = player->pos->getX(), cur_y = player->pos->getY();
    board[cache[1]][cache[0]] = board[cur_y][cur_x];
    board[cur_y][cur_x] = player->getAvatar();
}
int main(){

    Board board;
    board.printBoard();
    
    while(true){
        board.movement();
        system("cls");
        board.update();
        board.printBoard();
    }
}
