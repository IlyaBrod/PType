#ifndef CLASS_OBJECT_HPP
#define ClASS_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Rectangle.hpp"

class Object : public Point{
	protected :
		sf::Texture texture ;
		
		Rectangle hitbox;
		//frame rate for texture animation
		int frequency;
		
		//collision activated or not
		bool solid;
		
		virtual void inCollide();
		
	public :
		Object();
		Object(sf::Texture texture);
		Object(sf::Texture texture, Point origine, Rectangle box);
		
		
		void collide(Object obj);
		
		/**
		 * Display the object on the screen
		 * at position given by origine Point
		 */
		void display();
};

#endif
