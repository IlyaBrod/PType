#include "Weapon.hpp"

Weapon::Weapon(std::string texturePath, const int dmg): Object(texturePath), damage(dmg){}

Weapon::Weapon(){}

void Weapon::inCollide(Object* obj){

}
