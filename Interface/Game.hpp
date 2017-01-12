#ifndef CLASS_GAME_HPP
#define CLASS_GAME_HPP

#include <vector>
#include <iostream>
#include <fstream>

#include "../Game/Object.hpp"
#include "../Game/Bullet.hpp"
#include "../Game/Decor.hpp"
#include "../Game/Unit.hpp"
#include "../Game/Enemy.hpp"
#include "../Game/Player.hpp"
#include "../Game/Weapon.hpp"
#include "../Game/Item.hpp"
#include "../Game/Explosion.hpp"

class Game{
    protected :
        std::vector<Object*> objects ;
        std::ifstream levelFile ;
        int tick ;
    public :
        Game();

        void loadLevel(std::string path);
        void closeLevel();
        void checkEvent();
};


#endif
