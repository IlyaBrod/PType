#include "Decor.hpp"

Decor::Decor(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &solid, const bool &visible):
    Object(texturePath, origine, box, solid, visible){
    team = DECOR ;
}

void Decor::inCollide(Object* obj){
    switch(obj->get_team()){
        case PBULLET :
            obj->set_alive(false) ;
            break ;
        case EBULLET :
            obj->set_alive(false) ;
            break ;
        default :
            break ;
    }
}
