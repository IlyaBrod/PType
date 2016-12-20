#include "Weapon.hpp"

Weapon::Weapon(std::string texturePath, const int dmg): Object(texturePath), damage(dmg){}

Weapon::Weapon(){}

int Weapon::getDomage()
{
	return damage;
}

void Weapon::inCollide(Object &obj){

}
