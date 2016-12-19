/*#include "generalFunctions.hpp"
#include "Rectangle.hpp"
#include "Object.hpp"
#include "Item.hpp"
#include "Bullet.hpp"
#include "Unit.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Explosion.hpp"
#include "Decor.hpp"*/
#include "WEAPON_CONFIG.hpp"
#include "Weapon.hpp"
#include "generalFunctions.hpp"
#include <SFML/Window.hpp>
#include "Player.hpp"

using namespace std ;

int main(int argv, char** argc){

	/*
	const Weapon wpn_def[6] = {	Weapon(SHOVEL_PIC, SHOVEL_DMG)	, Weapon(VODKA_PIC, VODKA_DMG),
								Weapon(GUN_PIC, GUN_DMG)		, Weapon(LASER_PIC, LASER_DMG),
								Weapon(MISSILE_PIC, MISSILE_DMG), Weapon(NUKE_PIC, NUKE_DMG)	};

	*/

	Player poutine("poutine.png",Point(10,10),Rectangle(),10);
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Red);



        poutine.display(window);
        window.display();
    }

	
	return 0 ;
}

