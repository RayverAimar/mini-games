
#include "../headers/game.h"


constexpr auto UP = 119;
constexpr auto DOWN = 115;
constexpr auto RIGHT = 100;
constexpr auto LEFT = 97;
constexpr auto ESC = 27;

Game::Game(){
    m_playhandler = new PlayHandler();
    m_computer = new Computer('O');
    m_player = new Player('X');
    m_board = new char[9];
    for(int i = 0; i < 9; i++){
        m_board[i] = ' ';
    }
}

Game::~Game(){
    delete m_player, m_board, m_computer;
}

void Game::computer_movement(){
    int num_valid_movements{0}, counter{0};
    for(int i = 0; i < 9; i++){ //First, take the number exact of valid movements
        if(m_board[i] == ' '){
            num_valid_movements++;
        }
    }
    cout<<"Numero de movimientos validos\n";
    cout<<num_valid_movements<<"\n";
    int* valid_movements = new int[num_valid_movements];

    for(int i = 0; i < 9; i++){ //Then take its positions
        if(m_board[i] == ' '){
            valid_movements[counter] = i;
            counter++;
        }
    }

    cout<<"Estos son las posiciones de los movimientos validos de computer\n";
    for(int i = 0; i < num_valid_movements; i++){
        cout<<valid_movements[i]<<" ";
    }
    cout<<"\n";
    int computer_move = m_computer->ask_for_movement(num_valid_movements);
    m_board[valid_movements[computer_move]] = m_computer->getAvatar();
    m_computer->add_movement(valid_movements[computer_move]);
    cout<<"Estos es la posicion de los movimientos validos escogida\n";
    cout<<computer_move<<"\n";
    cout<<"Estos es la posicion del tablero escogida\n";
    cout<<valid_movements[computer_move]<<"\n";
    if(num_valid_movements != 1){
        set_PH_valid_position();    
    }
     // fix this when there is no valid position all positions already taken()
}

void Game::updateBoard(char _avatar, int pos){
    m_board[pos - 1] = _avatar; 
}

void Game::printBoard(){
    //system("cls");
    if(m_player->get_turn()){
        m_board[m_playhandler->get_last_pos()] = ' ';
        m_board[m_playhandler->get_pos()] = m_playhandler->get_avatar();
    }
    for(int i = 0; i < 9; i++){
        if(!(i%3)){
            cout<<"\n -------------\n";
            cout<<" |";
        }
        cout<<" "<<m_board[i]<<" |";
    }    
    cout<<"\n -------------\n\n";
}

bool Game::move_play_handler(){
    char key;

    while(key != RIGHT && key != LEFT && key != 13){ //Verifying that only RIGHT, LEFT or ENTER has been pressed
        key = _getch();
    }
    if(key == RIGHT){
        m_playhandler->move_pos(1, m_board);
    }
    if(key == LEFT){
        m_playhandler->move_pos(-1, m_board);
    }
    if(key == 13){
        m_player->shift_change();
        m_board[m_playhandler->get_pos()] = m_player->getAvatar();
        m_player->add_movement(m_playhandler->get_pos());
        cout<<"\n"<< "m_board en la posicion "<<m_playhandler->get_pos()<<" -> "<< m_board[m_playhandler->get_pos()]<<"\n\n";
        return false;
    }
    return true;

}

void Game::set_PH_valid_position(){
    m_playhandler->set_pos(0); //This function causing some issues
    while(m_board[m_playhandler->get_pos()] != ' '){
        m_playhandler->move_pos(1, m_board);
    }
    m_playhandler->set_last_pos(m_playhandler->get_pos());
}

bool Game::game_over(){

    if(m_computer->won()){
        cout<<"\nComputer made three in a row"<<endl;
        m_player->shift_change();
        return true;
    }
    if(m_player->won()){
        cout<<"\nYou made three in a row!"<<endl;
        return true;
    }

    for(int i = 0; i < 9; i++){
        if(m_board[i] == ' '){
            return false;
        }
    }
    system("cls");
    cout<<"Draw! Game has ended. All positions have been taken.\n";
    if(m_player->get_turn()){
        m_player->shift_change();
    }
    return true;
}