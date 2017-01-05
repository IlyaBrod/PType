#include "Unit.hpp"

Unit::Unit(std::string texturePath, Point point, Rectangle box ,int _life) : Object(texturePath, point, box), life(_life) {}

void Unit::inCollide(Object &obj)
{
	life+=weapon.getDomage();
}

void Unit::die()
{
	solid = false;
}
