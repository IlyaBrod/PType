#ifndef CLASS_RECTANGLE_HPP
#define CLASS_RECTANGLE_HPP

#include "generalFunctions.hpp"
#include "Point.hpp"

class Rectangle : public Point{
	protected :
		int width ;
		int height ;

	public :
	    Rectangle();
		Rectangle(const int &x, const int &y, const int &width, const int &height);
		Rectangle(const Point &pA, const Point &pB=Point());
		Rectangle(const Rectangle &rect);

		int getW()const ;
		int getH()const ;

		void setW(const int &width);
		void setH(const int &height);

		bool intersect(const Rectangle &rect)const;
};

#endif
