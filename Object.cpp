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
