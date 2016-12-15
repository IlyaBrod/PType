#ifndef CLASS_OBJECT_HPP
#define CLASS_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Rectangle.hpp"

class Object : public Point{
	protected :
    //the sprite (change texture into sprite)
		sf::Texture texture ;
    //Object hitbox is defined by a Rectangle
		Rectangle hitbox;
    //frame rate for texture animation
		int frequency;

    //collision activated or not
		bool solid;
    //object is visible or not
		bool visible;

    //implement collision effects (virtual function)
        virtual void inCollide(Object &obj)=0;

	public :
    //constructors
		Object();
		Object(sf::Texture texture);
		Object(sf::Texture texture, Point origine, Rectangle box);
		Object(sf::Texture texture, const Point &origine, const Rectangle &box, const bool &solid, const bool &visible);
    //accessors read
        bool get_solid()const{return solid;}
        bool get_visible()const{return visible;}
    //accessors write
        void set_solid(bool solid){this->solid = solid;}
        void set_visible(bool visible){this->visible = visible;}

    //check collision and get effects through inCollision function
		void collide(Object &obj);

		/**
		 * Display the object on the screen
		 * at position given by origine Point
		 */
		void display();
};

#endif
