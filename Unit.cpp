#include "Unit.hpp"

Unit::Unit(sf::Texture texture, Point point, int _life) : Object(texture, point), life(_life)

void Unit::inCollide()
{
	life+=weapon.getDomage();
}

void Unit::die()
{
	solid = false;
}
