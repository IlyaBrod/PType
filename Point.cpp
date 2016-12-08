#include "Point.hpp"

Point::Point(const int &_x, const int &_y): x(_x), y(_y){}
Point::Point(const Point &p): x(P.x), y(P.y){}

Point& operator=(const Point &p){
	this->x = p.x ;
	this->y = p.y ;
	return *this ;
}