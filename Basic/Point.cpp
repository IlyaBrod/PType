#include "Point.hpp"

Point::Point(const int &_x, const int &_y): x(_x), y(_y){}
Point::Point(const Point &p): x(p.x), y(p.y){}

Point& Point::operator=(const Point &p){
	x = p.x ;
	y = p.y ;
	return *this ;
}

Point& Point::operator+=(const Point &p){
	x += p.x ;
	y += p.y ;
	return *this;
}
Point& Point::operator-=(const Point &p){
	x -= p.x ;
	y -= p.y ;
	return *this;
}
Point Point::operator+(const Point &p){
	Point q(x+p.x, y+p.y);
	return q ;
}
Point Point::operator-(const Point &p){
	Point q(x-p.x, y-p.y);
	return q ;
}

int Point::getX()const{
	return x ;
}
int Point::getY()const{
	return y ;
}

void Point::setX(const int &_x){
	x = _x ;
}
void Point::setY(const int &_y){
	y = _y ;
}
