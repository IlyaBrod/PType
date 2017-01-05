#ifndef CLASS_ENEMY_HPP
#define CLASS_ENEMY_HPP

#include "Unit.hpp"

class Enemy : public Unit {
    protected :
        void inCollide(Object &obj);
};

#endif
