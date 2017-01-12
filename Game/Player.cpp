#include "Player.hpp"

Player::Player(std::string texturePath, Point point, sf::IntRect box, int life) : Unit(texturePath,point,box,life) {}

void Player::inCollide(Object* obj){
    switch(obj->get_team()){
        case PLAYER :

            break;
        case ENEMY :

            break ;
        case DECOR :
            alive = false ;
            break ;
        default :
            break ;
    }
}


