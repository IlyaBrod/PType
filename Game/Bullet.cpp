#include "Bullet.hpp"

Bullet::Bullet(): Object(), dmg(0){}

Bullet::Bullet(std::string texturePath, const Point &origine, const Rectangle &box, const bool &_solid, const bool &_visible, const int &_dmg):
    Object(texturePath, origine, box, _solid, _visible), dmg(_dmg)
{

}

void Bullet::inCollide(Object* obj){
    if(team != obj->get_team()){
        alive = false ;
        if(obj->get_team() != NEUTRAL){
            obj->inCollide(this);
        }
    }
}
