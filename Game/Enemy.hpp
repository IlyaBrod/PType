#ifndef CLASS_ENEMY_HPP
#define CLASS_ENEMY_HPP

#include "../Config/INTERFACE_CONFIG.hpp"
#include "Unit.hpp"
#include "Bullet.hpp"
#include "../Config/ENEMY_CONFIG.hpp"

#define ENEMY_DEFAULTSPEED 10

class Enemy : public Unit {
    protected :
        int speed ;
        int shootTick ;
        int movePattern ;
    public :
        Enemy(std::string texturePath);
        Enemy(std::string texturePath, Point point, sf::IntRect box, int life, int collideDmg);

        int getSpeed()const{return speed ;}

        void autoMove(int t, Object *obj=NULL);

        Object* shoot();

        void inCollide(Object* obj);
        int getDamage(){return collideDmg ;}
        void addLives(const int nbLives){};
        void addBombs(const int nbBombs){};
        void addScore(const int scorePoints){};

        void present();
};

#endif
