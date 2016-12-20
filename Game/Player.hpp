#ifndef CLASS_PLAYER_HPP
#define CLASS_PLAYER_HPP

#include "Unit.hpp"

class Player : public Unit{

    protected :
        void inCollide(Object &obj);
        
    public:
		Player(std::string texturePath, Point point, Rectangle box, int life);
};

#endif
