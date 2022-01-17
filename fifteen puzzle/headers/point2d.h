#ifndef _POINT2D_H
    #define _POINT2D_H

    class Point2D{
        
        int m_x, m_y;
        
        public:
        //Constructor & Destructor
        Point2D(int x, int y);
        ~Point2D();

        //Setters
        bool move_x(bool mov); //mov = 1, move forward mov = 0, move back
        bool move_y(bool mov); //mov = 1, move forward mov = 0, move back
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();

    };

#endif