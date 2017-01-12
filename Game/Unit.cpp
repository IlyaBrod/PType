#include "Unit.hpp"

Unit::Unit(std::string texturePath, Point point, sf::IntRect box ,int _life) : Object(texturePath, point, box), life(_life) {}
Unit::Unit(std::string texturePath, Point point, sf::IntRect box ,int _life, int _collideDmg) :
    Object(texturePath, point, box), life(_life), collideDmg(_collideDmg) {}



void Unit::die()
{
	solid = false;
}
