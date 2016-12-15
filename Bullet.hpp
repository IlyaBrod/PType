#ifndef CLASS_ENEMY_HPP
#define CLASS_ENEMY_HPP

#include "Bullet.hpp"

class Shot : public Bullet{
    protected :
        void inCollide();
};

#endif
