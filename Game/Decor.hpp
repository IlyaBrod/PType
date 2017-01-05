#ifndef CLASS_DECOR_HPP
#define CLASS_DECOR_HPP

#include "Object.hpp"

class Decor : public Object{
    protected :

    public :
        void inCollide(Object* obj);
        int getDamage(){return 0 ;}
};

#endif
