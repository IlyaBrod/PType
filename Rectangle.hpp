#ifndef CLASS_RECTANGLE_HPP
#define CLASS_RECTANGLE_HPP

#include "generalFunctions.hpp"
#include "Point.hpp"

class Rectangle : public Point{
	protected :
		int width ;
		int height ;

	public :
    //constructors
	    Rectangle();
		Rectangle(const int &x, const int &y, const int &width, const int &height);
		Rectangle(const Point &pA, const Point &pB=Point());
		Rectangle(const Rectangle &rect);
    //accessors read
		int getW()const ;
		int getH()const ;
    //accessors write
		void setW(const int &width);
		void setH(const int &height);
    //check Rectangles intersection
		bool intersect(const Rectangle &rect)const;
};

#endif
