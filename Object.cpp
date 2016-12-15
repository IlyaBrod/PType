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

Object::Object(sf::Texture texture, const Point &origine, const Rectangle &box, const bool &_solid, const bool &_visible):
    Point(origine), hitbox(box), solid(_solid), visible(_visible)
{
	this->texture = texture;
}


void Object::inCollide()
{

}
void Object::collide(const Object &obj)
{
	if(solid && hitbox.intersect(obj.hitbox) && obj.solid)
	{
		inCollide();
	}

}

void Object::display()
{
    if(visible){
        //display the texture
    }
}
