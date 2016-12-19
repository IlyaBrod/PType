#include "Bullet.hpp"

Bullet::Bullet(): Object(), dmg(0), team(PLAYER){}

Bullet::Bullet(std::string texturePath, const Point &origine, const Rectangle &box, const bool &_solid, const bool &_visible, const int &_dmg, const bool _team):
    Object(texturePath, origine, box, _solid, _visible), dmg(_dmg), team(_team)
{

}

void Bullet::inCollide(Object &obj){

}
