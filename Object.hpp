#ifndef CLASS_OBJECT_HPP
#define ClASS_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"

class Object : Point{
	protected :
		sf::Texture texture ;
	public :
		Object();
		Object(sf::Texture texture);
		Object(sf::Texture texture, Point point);
};

#endif
