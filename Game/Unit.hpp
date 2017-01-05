#ifndef CLASS_UNIT_HPP
#define CLASS_UNIT_HPP

#include "Object.hpp"
#include "Weapon.hpp"

class Unit : public Object{
	protected :
		int life ;
		int collideDmg ;
		Weapon weapon;
		//Weapon* weapons[];

	public :
		Unit(std::string texturePath, Point point, Rectangle box, int life);
		Unit(std::string texturePath, Point point, Rectangle box, int life, int collideDmg);

		void inCollide(Object* obj);

		void die();
};

#endif
