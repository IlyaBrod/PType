#include "Item.hpp"

void Item::inCollide(Object* obj){
    if(obj->get_team()==PLAYER){
        alive = false ;
        obj->inCollide(this);
    }
}
