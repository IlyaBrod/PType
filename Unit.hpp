#ifndef CLASS_OBJECT_HPP
#define ClASS_OBJECT_HPP

#include "Object.hpp"

class Unit : Object{
	protected :
		int life ;
	public :
		Unit(sf::Texture texture, Point point, int life);
};

#endif
