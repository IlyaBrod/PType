#include "Item.hpp"

void Item::inCollide(Object* obj){
    switch(obj->get_team()){
        case PLAYER :
            alive = false ;
            obj->addLife(lifeEffect);
            obj->addBombs(bombUp);
            obj->addLives(oneUp);
            obj->addScore(scoreUp);
            break;
        default :
            break ;
    }
}
