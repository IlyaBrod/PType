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
}

void Player::addPower(const int powerUp){
    wpn_power[select_wpn] += powerUp ;
    if(wpn_power[select_wpn] < MAXPOWER)
        wpn_power[select_wpn] = MAXPOWER ;
}
