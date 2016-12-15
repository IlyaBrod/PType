#ifndef CLASS_OBJECT_HPP
#define CLASS_OBJECT_HPP

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
		//object is visible
		bool visible;

        virtual void inCollide();

	public :
		Object();
		Object(sf::Texture texture);
		Object(sf::Texture texture, Point origine, Rectangle box);
        //accessors
        bool get_solid()const{return solid;}
        bool get_visible()const{return visible;}
        //setters
        void set_solid(bool solid){this->solid = solid;}
        void set_visible(bool visible){this->visible = visible;}


		void collide(const Object &obj);

		/**
		 * Display the object on the screen
		 * at position given by origine Point
		 */
		void display();
};

#endif
