#ifndef CLASS_OBJECT_HPP
#define ClASS_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"

class Object : public Point{
	protected :
		sf::Texture texture ;
		Point origine;
		
		//frame rate for texture animation
		int frequency;
		
		//collision activated or not
		bool collide;
		
	public :
		Object();
		Object(sf::Texture texture);
		Object(sf::Texture texture, Point point);
		
		/**
		 * Display the object on the screen
		 * at position given by origine Point
		 */
		void Display();
};

#endif
