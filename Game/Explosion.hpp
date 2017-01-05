#ifndef CLASS_EXPLOSION_HPP
#define CLASS_EXPLOSION_HPP

#include "Object.hpp"

class Explosion : public Object{
    protected :

    public :
        void inCollide(Object* obj);
        int getDamage(){return 0 ;}
};

#endif
