#include "Object.hpp"

Object::Object():Point()
{
	hitbox = Rectangle();
}


Object::Object(sf::Texture texture):Point()
{
	
	hitbox = Rectangle();
	this->texture = texture;
	
}

Object::Object(sf::Texture texture,Point origine,Rectangle box):Point(origine.getX(),origine.getY())
{
	hitbox = box;
	this->texture = texture;	
}


void Object::Display()
{
	
	
}
