#ifndef CLASS_POINT_HPP
#define ClASS_POINT_HPP

class Point{
	protected :
		int x ;
		int y ;
	public :
		Point(const int &x=0, const int &y=0);
		Point(const Point &p);

		Point& operator=(const Point &p);
		Point& operator+=(const Point &p);
		Point& operator-=(const Point &p);
		Point operator+(const Point &p);
		Point operator-(const Point &p);
};

#endif
