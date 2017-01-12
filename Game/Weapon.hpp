#ifndef CLASS_WEAPON_HPP
#define CLASS_WEAPON_HPP

#include "Object.hpp"
#include "../Config/WEAPON_CONFIG.hpp"

class Weapon : public Object
{
	protected :
		int damage ;
	public :
		Weapon();
		Weapon(std::string texturePath, const int dmg);

		void inCollide(Object* obj);
		int getDamage(){return damage ;}
};

#endif
