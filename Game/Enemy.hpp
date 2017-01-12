#ifndef CLASS_ENEMY_HPP
#define CLASS_ENEMY_HPP

#include "Unit.hpp"

class Enemy : public Unit {
    protected :

    public :
        Enemy(std::string texturePath, Point point, sf::IntRect box, int life, int collideDmg);

        void inCollide(Object* obj);
        int getDamage(){return collideDmg ;}
        void addLives(const int nbLives){};
        void addBombs(const int nbBombs){};
        void addScore(const int scorePoints){};
};

#endif
