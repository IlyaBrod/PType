#ifndef CLASS_OBJECT_HPP
#define CLASS_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Rectangle.hpp"

class Object : public Point{
	protected :
    //Material : sprite + texture
		Material mat;
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
		Object(std:string texturePath);
		Object(std:string texturePath, Point origine, Rectangle box);
		Object(std:string texturePath, const Point &origine, const Rectangle &box, const bool &solid, const bool &visible);
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
