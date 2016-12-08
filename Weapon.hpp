#ifndef CLASS_WEAPON_DEFINED
#define CLASS_WEAPON_DEFINED

#include "Object.hpp"
#include "WEAPON_CONFIG.hpp"

enum Weapon_Type{Shovel, Vodka, Gun, Laser, Missile, Nuke};

class Weapon : public Object{
	protected :
		int damage ;

	public :
		Weapon(sf::Texture texture, const int dmg);
};

#endif