#ifndef CLASS_PLAYER_HPP
#define CLASS_PLAYER_HPP

#include "Unit.hpp"

class Player : public Unit{

    protected :
        Weapon_Type select_wpn ;
        int wpn_power[WPN_TYPE_NB];
        int lives ;
        int bombs ;
        int score ;
    public:
		Player(std::string texturePath, Point point, Rectangle box, int life);

        void inCollide(Object* obj);
		int getDamage(){return collideDmg ;}
		void addLives(const int nbLives){lives += nbLives ;}
		void addBombs(const int nbBombs){bombs += nbBombs ;}
		void addScore(const int scorePoints){score += scorePoints ;}
};

#endif
