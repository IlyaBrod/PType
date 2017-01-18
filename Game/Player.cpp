#include "Player.hpp"

Player::Player(std::string texturePath, Point point, sf::IntRect box, int life) : Unit(texturePath,point,box,life) {}

void Player::inCollide(Object* obj){
    switch(obj->get_team()){
        case ENEMY :
            life += obj->getDamage();
            obj->set_alive(false);
            break ;
        case EBULLET :
            life += obj->getDamage();
            obj->set_alive(false);
            break ;
        case ITEM :
            obj->inCollide(this);
            break ;
        default :
            break ;
    }
    if(life<=0){
        setX(getTextureWidth());
        setY(getTextureHeight()*2);
        lives-- ;
        if(lives <= 0)
            alive = false ;
    }
}

void Player::move(int x, int y){
    setX(getX()+x);
    if(getX()<0)
        setX(0);
    if(getY()<0)
        setY(0);
    if(getX()>SCREENW)
        setX(SCREENW);
    if(getY()>SCREENH)
        setY(SCREENH);
    setY(getY()+y);
    Sprite::move(x,y);
}

void Player::addPower(const int powerUp){
    wpn_power[select_wpn] += powerUp ;
    if(wpn_power[select_wpn] < MAXPOWER)
        wpn_power[select_wpn] = MAXPOWER ;
}

Object* Player::shoot(){
    Bullet* bullet = new Bullet();
    return bullet ;
}
