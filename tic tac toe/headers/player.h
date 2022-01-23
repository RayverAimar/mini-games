#ifndef _PLAYER_H_
#define _PLAYER_H_



class Player{

    int* m_movements, num_movements;
    char m_avatar;
    bool m_turn;

public:

    Player(char _avatar);
    ~Player();
    char getAvatar();
    void print_moves();
    int get_num_movements();
    void add_movement(int _movement);
    void shift_change();
    bool get_turn();
    bool find(int _board_position);
    bool won();
};


#endif