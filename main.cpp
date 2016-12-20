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
#include "Material.hpp"
#include <iostream>
using namespace std ;

typedef enum {inMenu,inOption,inGame,inPause,inScore,inExit} gSTATE;

int main(int argv, char** argc){


	//##################       INIT    	################################
	/*
	const Weapon wpn_def[6] = {	Weapon(SHOVEL_PIC, SHOVEL_DMG)	, Weapon(VODKA_PIC, VODKA_DMG),
								Weapon(GUN_PIC, GUN_DMG)		, Weapon(LASER_PIC, LASER_DMG),
								Weapon(MISSILE_PIC, MISSILE_DMG), Weapon(NUKE_PIC, NUKE_DMG)	};

	*/

	Player poutine("poutine.png",Point(0,0),Rectangle(),5);
	poutine.scale(0.2,0.2);
	poutine.move(100,100);
	
	
	//Global game
	gSTATE gameStatus = inMenu;
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "P-Type");

	//##################	MAIN LOOP	################################
    while (gameStatus!=inExit) //window.isOpen()
    {

		//EVENTS
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
                gameStatus=inExit;
            }
        }


		//DISPLAY
		window.clear(sf::Color::Black);
		
		switch(gameStatus)
		{
			case(inMenu):
				break;
			case(inOption):
				break;
			case(inScore):
				break;
			case(inGame):
				poutine.draw(window);
			case(inPause):
				break;
			default:
				break;
		}
		
        window.display();
    }

	
	return 0 ;
}

