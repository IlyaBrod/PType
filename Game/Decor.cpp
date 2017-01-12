#include "Decor.hpp"

void Decor::inCollide(Object* obj){
    switch(obj->get_team()){
        case PBULLET :
            obj->alive = false ;
            break ;
        case EBULLET :
            obj->alive = false ;
            break ;
        default :
            break ;
    }
}
