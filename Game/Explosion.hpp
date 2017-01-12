#ifndef CLASS_EXPLOSION_HPP
#define CLASS_EXPLOSION_HPP

#include "Object.hpp"

class Explosion : public Object{
    protected :
        int ticks ;
    public :
        Explosion();
        Explosion(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &solid, const bool &visible, const int tick);

        void inCollide(Object* obj);
        int getDamage(){return 0 ;}
};

#endif
