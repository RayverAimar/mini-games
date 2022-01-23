#ifndef _PLAYER_H_
#define _PLAYER_H_



class Player{

    int* m_movements, num_movements;
    char m_avatar;
    bool m_turn;

public:

    //Constructors & Destructor
    Player(char _avatar);
    ~Player();

    //Getters
    char getAvatar();
    int get_num_movements();
    bool get_turn();
    bool find(int _board_position);
    bool won();

    //Setters (NULL)
    
    //Auxiliar Functions
    void print_moves();
    void add_movement(int _movement);
    void shift_change();
    
    
};


#endif