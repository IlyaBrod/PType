#ifndef CLASS_BULLET_HPP
#define CLASS_BULLET_HPP

#include "Object.hpp"

enum Team{PLAYER, ENEMY};

class Bullet : public Object{
    protected :
        int dmg ;
        bool team ;
        //inCollide function : destroy bullet (set solid = false)
        void inCollide(Object &obj);

    public :
        Bullet();
        Bullet(std::string texturePath, const Point &origine, const Rectangle &box, const bool &solid, const bool &visible, const int &dmg, const bool team);


};

#endif
