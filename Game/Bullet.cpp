#include "Bullet.hpp"

Bullet::Bullet(): Object(), dmg(0){}

Bullet::Bullet(std::string texturePath, const Point &origine, const Team _team) : Object(texturePath){
    setX(origine.getX());
    setY(origine.getY());

    hitbox.left = getX();
    hitbox.top = getY();
    hitbox.width = getTextureWidth();
    hitbox.height = getTextureHeight();
    sf::Sprite::setPosition(hitbox.left, hitbox.top);

    set_team(_team);
    alive = true ;
    visible = true ;
    solid = true ;
}

Bullet::Bullet(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &_solid, const bool &_visible, const int &_dmg, const Team _team):
    Object(texturePath, origine, box, _solid, _visible), dmg(_dmg)
{
    if(_team == PBULLET || _team == EBULLET)
        team = _team ;
    else
        team = EBULLET ;
}

void Bullet::inCollide(Object* obj){
    switch(obj->get_team()){
        case PLAYER :
            if(team == EBULLET){
                obj->addLife(dmg);
                alive = false ;
            }
            break;
        case ENEMY :
            if(team == PBULLET){
                obj->addLife(dmg);
                alive = false ;
            }
            break ;
        case DECOR :
            alive = false ;
            break ;
        default :
            break ;
    }
}

void Bullet::autoMove(int t, Object* obj){
    switch(t){
        case STRAIGHT :
            if(get_team()==PBULLET){
                move(DEFAULT_BULLETSPEED, 0);
                Sprite::move(DEFAULT_BULLETSPEED, 0);
            }else{
                move(-DEFAULT_BULLETSPEED, 0);
                Sprite::move(-DEFAULT_BULLETSPEED, 0);
            }
            break ;
        default:
            break;
    }
    if(getX() < -255 || getX() > SCREENW+255 || getY() < -128 || getX() > SCREENH+128)
        alive = false ;
}
