#include "Enemy.hpp"

void Enemy::inCollide(Object* obj){
    switch(obj->get_team()){
        case PLAYER :
            alive = false ;
            life = 0 ;
            obj->addLife(collideDmg);
            break ;
        case PBULLET :
            addLife(obj->getDamage());
            break ;
        case DECOR :
            break ;
        default :
            break ;
    }
}
