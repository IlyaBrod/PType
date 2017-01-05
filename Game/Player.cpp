#include "Player.hpp"

Player::Player(std::string texturePath, Point point, Rectangle box, int life) : Unit(texturePath,point,box,life) {}

void Player::inCollide(Object* obj){
    if(team != obj->get_team()){
        life += obj->getDamage();
    }
}


