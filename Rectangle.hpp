#ifndef CLASS_RECTANGLE_DEFINED
#define CLASS_RECTANGLE_DEFINED

#include "generalFunctions.hpp"
#include "Point.hpp"

class Rectangle : public Point{
	protected : 
		int width ;
		int height ;

	public :
		Rectangle(const int &x=0, const int &y=0, const int &width=0, const int &height=0);

		int getW()const ;
		int getH()const ;

		void setW(const int &width);
		void setH(const int &height);

		bool intersect(const Rectangle &rect)const;
};

#endif