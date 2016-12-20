#ifndef CLASS_ITEM_HPP
#define CLASS_ITEM_HPP

#include "Object.hpp"

class Item : public Object{

    protected :
        void inCollide(Object &obj);
};

#endif
