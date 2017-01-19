#ifndef CLASS_PLAYER_HPP
#define CLASS_PLAYER_HPP

#include "Unit.hpp"
#include "Bullet.hpp"

#define MAXPOWER 255

class Player : public Unit{

    protected :
        Weapon_Type select_wpn ;
        int wpn_power[WPN_TYPE_NB];
        int lives ;
        int bombs ;
        int score ;
    public:
		Player(std::string texturePath, Point point, sf::IntRect box, int life);

        void move(int x, int y);

        void inCollide(Object* obj);
		int getDamage(){return collideDmg ;}
		void addLives(const int nbLives){lives += nbLives ;}
		void addBombs(const int nbBombs){bombs += nbBombs ;}
		void addScore(const int scorePoints){score += scorePoints ;}
        void addPower(const int powerUp);

        void autoMove(int t, Object* obj=NULL) {}

        Bullet* shoot();

        void setWeapon(const Weapon_Type wpn){select_wpn = wpn ;}

        void present();
};

#endif
