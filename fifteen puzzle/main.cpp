#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <string>
#include <conio.h>
#include <vector>
#include <cstdlib>      // std::rand, std::srand


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
    void setX(int x);
    void setY(int y);
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

void Point2D::setX(int x){ m_x =  x;} 

void Point2D::setY(int y){ m_y =  y;} 


class Player{ 
    string m_avatar;
    public:
    Player();
    ~Player();
    Point2D *pos;
    string getAvatar();
};

Player::Player(){
    pos = new Point2D(0,0);
    m_avatar = "  ";
}

Player::~Player(){

}

string Player::getAvatar(){ return m_avatar; }

class Board{
    vector<string> unsorted_board;
    Player *player;
    int *cache;
    int num_movements;
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
    num_movements = 0;
    for(int i = 0; i < 15; i++){
        if(i < 9){
            unsorted_board.push_back("0" + to_string(i + 1));
            }
        else{
            unsorted_board.push_back(to_string(i + 1 ));
        }
    }
    unsorted_board.push_back(player->getAvatar());
    srand ( unsigned ( time(0) ) );
    random_shuffle(unsorted_board.begin(), unsorted_board.end());

    int aux = 0;
    for(int i = 0; i < 4; i++ ){
        for (int j = 0; j < 4; j++){
            if(aux < 9){
                solved[i][j] = "0" + to_string(aux + 1);
            }
            else{
                solved[i][j] = to_string(aux + 1);
            }
            board[i][j] = unsorted_board[aux];
            if(board[i][j] == "  "){
                player->pos->setX(j);
                player->pos->setY(i);
            }
            aux++;
        }
    }

    solved[3][3] = player->getAvatar();
    cache[0] = player->pos->getX();
    cache[1] = player->pos->getY();
}

Board::~Board(){

}

bool Board::game_over(){
    if(!(num_movements%10) && num_movements){
        char temp;
        cout<<num_movements<<" attempts were given\n";
        cout<<"This puzzle could probably has no solution\n";
        cout<<"Do you want to keep trying?(y/n): ";
        cin>>temp;
        while(!(temp == 'y' || temp == 'n')){
            system("cls");
            cout<<"Please enter a valid option\n";
            cout<<"Do you want to keep trying?(y/n): ";
            cin>>temp;
        }
        if(temp == 'n'){
            cout<<" \nGame over!\n";
            return true;
        }
        else{
            printBoard();
            return false;
        }
    }
    for(int i = 0 ; i < 4; i++ ){
        for(int j = 0; j < 4; j++){
            if(!(board[i][j] == solved[i][j])){
                return false;
            }
        }
    }

    cout<<"Puzzle done! Congratulations!\n";
    cout<<"The number of movements made was: "<<num_movements<<"\n";
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
    num_movements++;
    cout<<"\nNumber of movements: "<<num_movements<<"\n";
    
}
int main(){

    Board board;
    system("cls");
    board.printBoard();
    cout<<"\nPress w a s d to move. . . ";
    while(!board.game_over()){
        if(board.movement()){
            system("cls");
            board.update();
            board.printBoard();
        }
    }
}
