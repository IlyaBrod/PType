#ifndef CLASS_ENEMY_HPP
#define CLASS_ENEMY_HPP

#include "Unit.hpp"

class Enemy : public Unit {
    protected :

    public :

        void inCollide(Object* obj);
        int getDamage(){return collideDmg ;}
};

#endif
