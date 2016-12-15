#ifndef CLASS_EXPLOSION_HPP
#define CLASS_EXPLOSION_HPP

#include "Object.hpp"

class Explosion : public Object{
    protected :
        void inCollide(Object &obj);
};

#endif
