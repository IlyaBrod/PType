#ifndef CLASS_ENEMY_HPP
#define CLASS_ENEMY_HPP

#include "Unit.hpp"

#define ENEMY_DEFAULTSPEED 10

class Enemy : public Unit {
    protected :
        int speed ;
    public :
        Enemy(std::string texturePath, Point point, sf::IntRect box, int life, int collideDmg);

        int getSpeed()const{return speed ;}

        void autoMove(int t, Object *obj=NULL);

        void inCollide(Object* obj);
        int getDamage(){return collideDmg ;}
        void addLives(const int nbLives){};
        void addBombs(const int nbBombs){};
        void addScore(const int scorePoints){};
};

#endif
