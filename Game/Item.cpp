#include "Item.hpp"

void Item::inCollide(Object* obj){
    switch(obj->get_team()){
        case PLAYER :

            break;
        case ENEMY :

            break ;
        case DECOR :
            alive = false ;
            break ;
        default :
            break ;
    }
}
