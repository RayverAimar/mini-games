#include <iostream>

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
    void move_x(bool mov); //mov = 1, move forward
    void move_y(bool mov); //mov = 0, move back
    int getX();
    int getY();
    void print_values(){ cout<<m_x<<endl<<m_y<<endl;}

};

Point2D::Point2D(int x, int y): m_x(x), m_y{y}{}

Point2D::~Point2D(){

}

void Point2D::move_x(bool mov){
    int back_up = m_x;
    if(mov) m_x++;
    else m_x--;
    if(m_x < 0 && m_x > 3) m_x = back_up;
}
void Point2D::move_y(bool mov){
    int back_up = m_y;
    if(mov) m_y++;
    else m_y--;
    if(m_y < 0 && m_y > 3) m_y = back_up;
}

int Point2D::getX(){ return m_x; }

int Point2D::getY(){ return m_y; }

class Player{
    int m_avatar;
    public:
    Player();
    ~Player();
    int getAvatar();
};

Player::Player(){
    Point2D pos(3,3);
    m_avatar = 0;
}

Player::~Player(){

}

int Player::getAvatar(){ return m_avatar; }

class Board{
    int board[4][4];

    public:

    Board();
    ~Board();

    void printBoard();
    void update();
};

Board::Board(){
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

void Board::update(){

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

int main(){
    Board board;
    board.printBoard();
}