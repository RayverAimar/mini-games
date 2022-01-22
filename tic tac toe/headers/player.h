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
    int get_num_movements();
    int* get_m_movements();
    void add_movement(int _movement);
    void increment_num_movements();
    void shift_change();
    bool get_turn();
};


#endif