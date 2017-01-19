#ifndef CLASS_POINT_HPP
#define CLASS_POINT_HPP

class Point{
	protected :
		int x ;
		int y ;
	public :
		Point(const int &x=0, const int &y=0);
		Point(const Point &p);

		virtual ~Point(){}

		Point& operator=(const Point &p);
		Point& operator+=(const Point &p);
		Point& operator-=(const Point &p);
		Point operator+(const Point &p);
		Point operator-(const Point &p);

		int getX()const ;
		int getY()const ;

		void setX(const int &x);
		void setY(const int &y);
};

#endif
