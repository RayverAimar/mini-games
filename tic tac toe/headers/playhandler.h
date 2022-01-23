#ifndef _PLAYHANDLER_H_
#define _PLAYHANDLER_H_


class PlayHandler{
    char m_avatar;
    int m_pos, m_last_pos;
public:

    //Constructors & Destructor
    PlayHandler(int _pos = 0);
    ~PlayHandler();

    //Getters
    int get_last_pos();
    int get_pos();
    char get_avatar();

    //Setters
    void set_pos(int _pos);
    void set_last_pos(int _last_pos);

    //Auxiliar Functions
    void move_pos(int _to_move, char* m_board);
    
};



#endif