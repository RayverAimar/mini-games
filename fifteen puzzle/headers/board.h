#ifndef _BOARD_H_
    #define _BOARD_H_

    #include <vector>
    #include "player.h"

    using std::vector; using std::string;

    class Board{

        std::vector<string> unsorted_board;
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

#endif