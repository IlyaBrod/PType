#include "Object.hpp"

Object::Object():Point()
{
	
}


Object::Object(sf::Texture texture):Point()
{
	this->texture = texture;
	
}

Object::Object(sf::Texture texture,Point point):Point(point.getX(),point.getY())
{
	this->texture = texture;	
}


void Object::Display()
{
	
	
}
