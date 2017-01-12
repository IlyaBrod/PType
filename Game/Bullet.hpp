#ifndef CLASS_BULLET_HPP
#define CLASS_BULLET_HPP

#include "Object.hpp"

class Bullet : public Object{
    protected :
        int dmg ;
    public :
        Bullet();
        Bullet(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &_solid, const bool &_visible, const int &_dmg, const Team _team);

        //inCollide function : destroy bullet (set solid = false)
        void inCollide(Object* obj);
        int getDamage(){return dmg ;}

};

#endif
