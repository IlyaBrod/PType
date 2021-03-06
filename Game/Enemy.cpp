#include "Enemy.hpp"

Enemy::Enemy(std::string texturePath): Unit(texturePath, Point(SCREENW, SCREENH*(rand()%16)/16), sf::IntRect(0,0,0,0), 16, 16){
    hitbox.left = getX();
    hitbox.top = getY();
    hitbox.width = getTextureWidth();
    hitbox.height = getTextureHeight();
    sf::Sprite::setPosition(hitbox.left, hitbox.top);

    speed = ENEMY_DEFAULTSPEED ;
    shootTick = 16 ;
    movePattern = rand()%3 ;
    team = ENEMY;
    solid = true ;
    visible = true ;
    alive = true ;
}

Enemy::Enemy(std::string texturePath, Point point, sf::IntRect box, int life, int collideDmg):
    Unit(texturePath, point, box, life, collideDmg){
    speed = ENEMY_DEFAULTSPEED ;
    shootTick = 16 ;
    movePattern = rand()%3 ;
    team = ENEMY;
    solid = true ;
    visible = true ;
    alive = true ;
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
            if(life<=0)
                alive = false ;
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
    if(getX() < -255 || getX() > SCREENW+255 || getY() < -128 || getY() > SCREENH+128)
        alive = false ;
}

Object* Enemy::shoot(){
    shootTick-- ;
    if(shootTick <= 0){
        shootTick = 16 ;
        Bullet* bullet = new Bullet();
        return bullet ;
    }
    return NULL ;
}


void Enemy::present(){
    Unit::present();
}
