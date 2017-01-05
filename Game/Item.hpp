#ifndef CLASS_ITEM_HPP
#define CLASS_ITEM_HPP

#include "Object.hpp"

class Item : public Object{
    protected :
        int lifeEffect ; //effect on life

    public :

        void inCollide(Object* obj);
        int getDamage(){return lifeEffect ;}
};

#endif
