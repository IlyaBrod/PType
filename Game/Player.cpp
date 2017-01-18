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
    setY(getY()+y);
    if(getX()<getTextureWidth())
        setX(getTextureWidth());
    if(getY()<getTextureHeight()/4)
        setY(getTextureHeight()/4);
    if(getX()>SCREENW-getTextureWidth()*3/2)
        setX(SCREENW-getTextureWidth()*3/2);
    if(getY()>SCREENH-getTextureHeight())
        setY(SCREENH-getTextureHeight());
    Sprite::setPosition(getX(),getY());
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
