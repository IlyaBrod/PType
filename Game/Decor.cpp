#include "Decor.hpp"

void Decor::inCollide(Object* obj){
    if(obj->get_team()!=DECOR){
        obj->inCollide(this);
    }
}
