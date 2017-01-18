#ifndef CLASS_BULLET_HPP
#define CLASS_BULLET_HPP

#include "../Config/INTERFACE_CONFIG.hpp"
#include "Object.hpp"

#define DEFAULT_BULLETSPEED 20

class Bullet : public Object{
    protected :
        int dmg ;
        Weapon_Type type ;
    public :
        Bullet();
        Bullet(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &_solid, const bool &_visible, const int &_dmg, const Team _team);

        //inCollide function : destroy bullet (set solid = false)
        void autoMove(int t, Object *obj=NULL);

        void inCollide(Object* obj);
        int getDamage(){return dmg ;}

};

#endif
