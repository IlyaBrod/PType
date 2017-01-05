#ifndef CLASS_PLAYER_HPP
#define CLASS_PLAYER_HPP

#include "Unit.hpp"

class Player : public Unit{

    protected :

    public:
		Player(std::string texturePath, Point point, Rectangle box, int life);

        void inCollide(Object* obj);
		int getDamage(){return collideDmg ;}
};

#endif
