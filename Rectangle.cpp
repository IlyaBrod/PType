#include "Rectangle.hpp"

Rectangle(const int &_x, const int &_y, const int &_width, const int &_height): Point(_x, _y), width(_width), height(_height){}

int getW()const{
	return width ;
}
int getH()const{
	return height ;
}

void setW(const int &_width){
	width = _width ;
}
void setH(const int &_height){
	height = _height ;
}

bool intersect(const Rectangle &rect)const{
	return (max(x, rect.x) <= min(x+width, rect.x+rect.width)) && (max(y, rect.y) <= mint(y+height, rect.y+rect.height));
}