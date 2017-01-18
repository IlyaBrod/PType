#ifndef CLASS_GAME_HPP
#define CLASS_GAME_HPP

#include <vector>
#include <iostream>
#include <fstream>

#include "../Config/PLAYER_CONFIG.hpp"
#include "../Config/INTERFACE_CONFIG.hpp"

#include "../Game/Object.hpp"
#include "../Game/Bullet.hpp"
#include "../Game/Decor.hpp"
#include "../Game/Unit.hpp"
#include "../Game/Enemy.hpp"
#include "../Game/Player.hpp"
#include "../Game/Weapon.hpp"
#include "../Game/Item.hpp"
#include "../Game/Explosion.hpp"
#include "../Basic/Material.hpp"

class Game{
    protected :
        std::vector<Object*> objects ;
        std::ifstream levelFile ;
        int tick ;
        
        float* scaleFactor;
        
        bool visible;
        Material* background;
        
    public :
        Game();
		
		Object* getObject(int i){return objects[i];}
		
        void loadLevel(std::string path);
        void closeLevel();
        void checkEvent();
        void draw(sf::RenderWindow& window);
        void setScaleFactor(float* scaleFactor);
        
        void backgroundMove();
};


#endif
