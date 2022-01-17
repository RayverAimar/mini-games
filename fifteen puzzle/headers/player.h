#ifndef _PLAYER_H_
    #define _PLAYER_H_

    #include "point2d.h"
    #include <string>

    using std::string;

    class Player{ 

    string m_avatar;

    public:
    Player();
    ~Player();
    Point2D *pos;
    string getAvatar();
};

#endif