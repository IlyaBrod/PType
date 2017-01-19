#ifndef CLASS_UNIT_HPP
#define CLASS_UNIT_HPP

#include "Object.hpp"
#include "Weapon.hpp"

class Unit : public Object{
	protected :
		int life ;
		int collideDmg ;
		//Weapon weapon;
		//Weapon* weapons[];

	public :
		Unit(std::string texturePath, Point point, sf::IntRect box, int life);
		Unit(std::string texturePath, Point point, sf::IntRect box, int life, int collideDmg);

        int getCollideDmg()const{return collideDmg;}
		//virtual void inCollide(Object* obj);

		void die();

		void addLife(const int adding){life += adding;}
        //void addLives(const int nbLives){}
		//void addBombs(const int nbBombs){}
        //void addScore(const int scorePoints){}

        virtual void present();
};

#endif
