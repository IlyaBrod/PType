#ifndef CLASS_DECOR_HPP
#define CLASS_DECOR_HPP

#include "Object.hpp"

class Decor : public Object{
    protected :
        void inCollide(Object &obj);
};

#endif
