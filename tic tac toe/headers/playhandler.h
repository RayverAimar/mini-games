#ifndef _PLAYHANDLER_H_
#define _PLAYHANDLER_H_


class PlayHandler{
    char m_avatar;
    int m_pos, m_last_pos;
    bool activity;
public:

    PlayHandler(int _pos = 0);
    ~PlayHandler();

    int get_last_pos();
    int get_pos();
    void set_pos(int _pos);
    bool get_activity();
    void move_pos(int _to_move, char* m_board);
    char get_avatar();
};



#endif