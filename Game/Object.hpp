#ifndef CLASS_OBJECT_HPP
#define CLASS_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../Basic/Point.hpp"
#include "../Basic/Rectangle.hpp"
#include "../Basic/Material.hpp"

enum Team{PLAYER, ENEMY, NEUTRAL};

class Object : public Point, public Material{
	protected :

    //Object hitbox is defined by a Rectangle
		Rectangle hitbox;
    //frame rate for texture animation
		int frequency;

    //collision activated or not
		bool solid;
    //object is visible or not
		bool visible;
    //Team of the Object
        Team team ;
    //is alive (if false, Object is destroyed at end of tick)
        bool alive ;

	public :
    //constructors
		Object();
		Object(std::string texturePath);
		Object(std::string texturePath, Point origine, Rectangle box);
		Object(std::string texturePath, const Point &origine, const Rectangle &box, const bool &solid, const bool &visible);
    //accessors read
        bool get_solid()const{return solid;}
        bool get_visible()const{return visible;}
        Team get_team()const{return team ;}
    //accessors write
        void set_solid(bool solid){this->solid = solid;}
        void set_visible(bool visible){this->visible = visible;}

    //implement collision effects (virtual function)
        virtual void inCollide(Object* obj)=0;
		/**
		 * Check collision and get effects through inCollision function
		 */
		void collide(Object* obj);
        virtual int getDamage(){return 0 ;};

};

#endif
