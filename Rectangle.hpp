#ifndef CLASS_RECTANGLE_DEFINED
#define CLASS_RECTANGLE_DEFINED

#include "Point.hpp"

class Rectangle : public Point{
	protected : 
		int length ;
		int height ;

	public :
		Rectangle(const int &x=0, const int &y=0, const int &length=0, const int &height=0);
};

#endif