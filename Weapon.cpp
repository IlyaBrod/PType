#include "Weapon.hpp"

Weapon::Weapon(sf::Texture texture, const int dmg): Object(texture), damage(dmg){}

int Weapon::getDomage()
{
	return damage;
}
