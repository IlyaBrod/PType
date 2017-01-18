#include "Enemy.hpp"

Enemy::Enemy(std::string texturePath, Point point, sf::IntRect box, int life, int collideDmg):
    Unit(texturePath, point, box, life, collideDmg){
    speed = ENEMY_DEFAULTSPEED ;
}

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

void Enemy::autoMove(int t, Object *obj){
    switch(t){
        case STRAIGHT :
            move(-speed, 0);
            break ;
        case HOMING :
            if(obj != NULL){
                int dx=obj->getX()-getX(), dy = obj->getY()-getY();
                move(dx/(dx+dy)*speed, dy/(dx+dy)*speed);
            }else{
                move(-speed, 0);
            }
            break ;
        case HOMING_STRAIGHT :
            if(obj != NULL){
                int dx=obj->getX()-getX(), dy = obj->getY()-getY();
                move(dx/(dx+dy)*speed/2, dy/(dx+dy)*speed/2);
            }
            move(-speed*2/3, 0);
            break ;
    }
}
