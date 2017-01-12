#include "Bullet.hpp"

Bullet::Bullet(): Object(), dmg(0){}

Bullet::Bullet(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &_solid, const bool &_visible, const int &_dmg, const Team _team):
    Object(texturePath, origine, box, _solid, _visible), dmg(_dmg)
{
    if(_team == PBULLET || _team == EBULLET)
        team = _team ;
    else
        team = EBULLET ;
}

void Bullet::inCollide(Object* obj){
    switch(obj->get_team()){
        case PLAYER :
            if(team == EBULLET){
                obj->addLife(dmg);
                alive = false ;
            }
            break;
        case ENEMY :
            if(team == PBULLET){
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
