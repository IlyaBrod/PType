#include "Unit.hpp"

Unit::Unit(sf::Texture texture, Point point, Rectangle box ,int _life) : Object(texture, point, box), life(_life) {}

void Unit::inCollide()
{
	life+=weapon.getDomage();
}

void Unit::die()
{
	solid = false;
}
