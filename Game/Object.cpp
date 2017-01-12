#include "Object.hpp"

Object::Object():Point(),Material()
{
	hitbox = sf::IntRect();
}

Object::Object(std::string texturePath):Point(),Material(texturePath)
{
	hitbox = sf::IntRect();

}

Object::Object(std::string texturePath, Point origine, sf::IntRect box):Point(origine.getX(),origine.getY()),Material(texturePath)
{
	hitbox = box;
}

Object::Object(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &_solid, const bool &_visible):
    Point(origine), Material(texturePath), hitbox(box), solid(_solid), visible(_visible) {}


void Object::inCollide(Object* obj)
{
    //virtual function does nothing
}
void Object::collide(Object* obj)
{
	if(alive && obj->alive && solid && obj->solid && hitbox.intersects(obj->hitbox))
	{
	    //implement collision effects
		inCollide(obj);
	}

}

void Object::move(int x, int y){
    setX(getX()+x);
    setY(getY()+y);
    Sprite::move(x,y);
}
