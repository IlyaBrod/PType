#ifndef CLASS_DECOR_HPP
#define CLASS_DECOR_HPP

#include "Object.hpp"

class Decor : public Object{
    protected :

    public :
        Decor();
        Decor(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &solid, const bool &visible);
        void inCollide(Object* obj);
        int getDamage(){return 0 ;}
};

#endif
