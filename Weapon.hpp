#ifndef CLASS_WEAPON_HPP
#define CLASS_WEAPON_HPP

#include "Object.hpp"
#include "WEAPON_CONFIG.hpp"

enum Weapon_Type{Shovel, Vodka, Gun, Laser, Missile, Nuke};

class Weapon : public Object
{
	protected :
		int damage ;
		void inCollide(Object &obj);
	public :
		Weapon();
		Weapon(std::string texturePath, const int dmg);

		int getDomage();
};

#endif
