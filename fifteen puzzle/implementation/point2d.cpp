#include "../headers/point2d.h"


Point2D::Point2D(int x, int y): m_x(x), m_y{y}{}

Point2D::~Point2D(){

}

bool Point2D::move_x(bool mov){
    int back_up = m_x;
    if(mov) { m_x++; }
    else { m_x--; }
    if(m_x < 0 || m_x > 3) {
        m_x = back_up; 
        return false;
    }
    return true;
}
bool Point2D::move_y(bool mov){
    int back_up = m_y;
    if(mov) {m_y++;}
    else {m_y--;}
    if(m_y < 0 || m_y > 3) { 
        m_y = back_up;
        return false; }// NO hubo movimiento
    return true; // Sí lo hubo
}

int Point2D::getX(){ return m_x; }

int Point2D::getY(){ return m_y; }

void Point2D::setX(int x){ m_x =  x;} 

void Point2D::setY(int y){ m_y =  y;} 
