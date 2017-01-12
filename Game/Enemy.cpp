#include "Enemy.hpp"

Enemy::Enemy(std::string texturePath, Point point, sf::IntRect box, int life, int collideDmg):
    Unit(texturePath, point, box, life, collideDmg){

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
