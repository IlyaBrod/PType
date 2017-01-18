#ifndef CLASS_OBJECT_HPP
#define CLASS_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../Basic/Point.hpp"
#include "../Basic/Rectangle.hpp"
#include "../Basic/Material.hpp"

#include "../Config/WEAPON_CONFIG.hpp"

#include <cstdlib>

enum {STRAIGHT, HOMING, HOMING_STRAIGHT};
enum Team{PLAYER, ENEMY, PBULLET, EBULLET, DECOR, ITEM};

class Object : public Point, public Material{
	protected :

    //Object hitbox is defined by a Rectangle
		sf::IntRect hitbox;
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
		Object(std::string texturePath, Point origine, sf::IntRect box);
		Object(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &solid, const bool &visible);
    //accessors read
        bool get_solid()const{return solid;}
        bool get_visible()const{return visible;}
        Team get_team()const{return team ;}
        bool get_alive()const{return alive;}
    //accessors write
        void set_solid(bool solid){this->solid = solid;}
        void set_alive(const bool alive){this->alive = alive ;}
        void set_visible(bool visible){this->visible = visible;}

        virtual void move(int x, int y);
    //implement collision effects (virtual function)
        virtual void inCollide(Object* obj)=0;
		/**
		 * Check collision and get effects through inCollision function
		 */
		void collide(Object* obj);
        int getDamage(){return 0 ;};

        virtual void autoMove(int t, const Object *obj=NULL){}
        virtual Object* shoot(){return NULL ;}

        virtual void addLife(int adding){}
        virtual void addLives(const int nbLives){}
        virtual void addBombs(const int nbBombs){}
        virtual void addScore(const int scorePoints){}
        virtual void addPower(const int powerUp){}
};

#endif
