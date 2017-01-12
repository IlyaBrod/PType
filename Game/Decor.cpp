#include "Decor.hpp"

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
