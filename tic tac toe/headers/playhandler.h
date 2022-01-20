#ifndef _PLAYHANDLER_H_
#define _PLAYHANDLER_H_


class PlayHandler{
    char m_avatar;
    int m_pos;
public:

    PlayHandler(int _pos);
    ~PlayHandler();

    int get_pos();
    bool move_pos(int _to_move);
    bool update_pos(int _to_move);
    void browse(int* &m_board);
    void printBoard(int* &m_board);
};



#endif