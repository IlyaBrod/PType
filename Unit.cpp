#include "Unit.hpp"

Unit::Unit(sf::Texture texture, Point point, int _life) : Object(texture, point), life(_life)