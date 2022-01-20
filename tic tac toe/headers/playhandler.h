#ifndef _PLAYHANDLER_H_
#define _PLAYHANDLER_H_


class PlayHandler{

    int m_pos;

public:

    PlayHandler(int _pos);
    ~PlayHandler();
    int get_pos();
    bool update_pos(int _to_move);
};



#endif