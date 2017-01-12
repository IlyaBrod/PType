#include "Bullet.hpp"

Bullet::Bullet(): Object(), dmg(0){}

Bullet::Bullet(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &_solid, const bool &_visible, const int &_dmg):
    Object(texturePath, origine, box, _solid, _visible), dmg(_dmg)
{

}

void Bullet::inCollide(Object* obj){
    switch(obj->get_team()){
        case PLAYER :
            if(team == ENEMY){
                obj->addLife(dmg);
                alive = false ;
            }
            break;
        case ENEMY :
            if(team == PLAYER){
                obj->addLife(dmg);
                alive = false ;
            }
            break ;
        case DECOR :
            alive = false ;
            break ;
        default :
            break ;
    }
}
