#include "Unit.hpp"

Unit::Unit(std::string texturePath, Point point, sf::IntRect box ,int _life) : Object(texturePath, point, box), life(_life) {
    solid = true ;
    visible = true ;
    alive = true ;
}

Unit::Unit(std::string texturePath, Point point, sf::IntRect box ,int _life, int _collideDmg) :
    Object(texturePath, point, box), life(_life), collideDmg(_collideDmg) {
    solid = true ;
    visible = true ;
    alive = true ;
}


void Unit::die()
{
	solid = false;
}


void Unit::present(){
    Object::present();
    std::cout << "  life:" << life << " CDmg:"<<collideDmg << std::endl ;
}
