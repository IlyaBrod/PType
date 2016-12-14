#include "Rectangle.hpp"

Rectangle::Rectangle(const int &_x, const int &_y, const int &_width, const int &_height): Point(_x, _y), width(_width), height(_height){}

int Rectangle::getW()const{
	return width ;
}
int Rectangle::getH()const{
	return height ;
}

void Rectangle::setW(const int &_width){
	width = _width ;
}
void Rectangle::setH(const int &_height){
	height = _height ;
}

bool Rectangle::intersect(const Rectangle &rect)const{
	return (max(x, rect.x) <= min(x+width, rect.x+rect.width)) && (max(y, rect.y) <= min(y+height, rect.y+rect.height));
}
