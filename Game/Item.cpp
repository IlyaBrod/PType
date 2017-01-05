#include "Item.hpp"

void Item::inCollide(Object* obj){
    if(obj->get_team()==PLAYER){
        alive = false ;
        obj->addLife(lifeEffect);
        obj->addBombs(bombUp);
        obj->addLives(oneUp);
        obj->addScore(scoreUp);
    }
}
