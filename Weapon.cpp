#include "Weapon.hpp"

Weapon::Weapon(sf::Texture texture, const int dmg): Object(texture), damage(dmg){}

Weapon::Weapon(){}

int Weapon::getDomage()
{
	return damage;
}

void Weapon::inCollide(){

}
