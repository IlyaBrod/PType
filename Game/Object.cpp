#include "Object.hpp"

Object::Object():Point(),Material()
{
	hitbox = Rectangle();
}

Object::Object(std::string texturePath):Point(),Material(texturePath)
{
	hitbox = Rectangle();

}

Object::Object(std::string texturePath, Point origine,Rectangle box):Point(origine.getX(),origine.getY()),Material(texturePath)
{
	hitbox = box;
}

Object::Object(std::string texturePath, const Point &origine, const Rectangle &box, const bool &_solid, const bool &_visible):
    Point(origine), Material(texturePath), hitbox(box), solid(_solid), visible(_visible) {}


void Object::inCollide(Object* obj)
{
    //virtual function does nothing
}
void Object::collide(Object* obj)
{
	if(solid && hitbox.intersect(obj->hitbox) && obj->solid)
	{
	    //implement collision effects
		inCollide(obj);
	}

}

