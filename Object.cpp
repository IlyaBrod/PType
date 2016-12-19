#include "Object.hpp"

Object::Object():Point()
{
	hitbox = Rectangle();
	mat = Material();
}

Object::Object(std::string texturePath):Point()
{

	hitbox = Rectangle();
	mat = Material(texturePath);

}

Object::Object(std::string texturePath, Point origine,Rectangle box):Point(origine.getX(),origine.getY())
{
	hitbox = box;
	mat = Material(texturePath);
}

Object::Object(std::string texturePath, const Point &origine, const Rectangle &box, const bool &_solid, const bool &_visible):
    Point(origine), hitbox(box), solid(_solid), visible(_visible)
{
	mat = Material(texturePath);
}


void Object::inCollide(Object &obj)
{
    //virtual function does nothing
}
void Object::collide(Object &obj)
{
	if(solid && hitbox.intersect(obj.hitbox) && obj.solid)
	{
	    //implement collision effects
		inCollide(obj);
	}

}

void Object::display(sf::RenderWindow& window)
{
    if(visible){
        mat.draw(window);
    }
}
