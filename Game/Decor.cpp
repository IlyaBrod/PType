#include "Decor.hpp"

void Decor::inCollide(Object* obj){
    switch(obj->get_team()){
        case PLAYER :
            break;
        case ENEMY :
            break ;
        case DECOR :
            break ;
        case ITEM :
            break ;
        default :
            break ;
    }
}
