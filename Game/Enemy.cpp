#include "Enemy.hpp"

void Enemy::inCollide(Object* obj){
    if(obj->get_team()==PLAYER){
        life += obj->getDamage();
        obj->inCollide(this);
    }
}
