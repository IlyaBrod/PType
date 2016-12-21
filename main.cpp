
#include <SFML/Window.hpp>
#include <iostream>


#include "Game/Player.hpp"
#include "Game/Weapon.hpp"

#include "Basic/generalFunctions.hpp"
#include "Basic/Material.hpp"

#include "Interface/Menu.hpp"

#include "Config/INTERFACE_CONFIG.hpp"
#include "Config/PLAYER_CONFIG.hpp"
#include "Config/WEAPON_CONFIG.hpp"

using namespace std ;

typedef enum {inMenu,inOption,inGame,inPause,inScore,inExit} gSTATE;

int main(int argv, char** argc){


	//##################       INIT    	################################
	/*
	const Weapon wpn_def[6] = {	Weapon(SHOVEL_PIC, SHOVEL_DMG)	, Weapon(VODKA_PIC, VODKA_DMG),
								Weapon(GUN_PIC, GUN_DMG)		, Weapon(LASER_PIC, LASER_DMG),
								Weapon(MISSILE_PIC, MISSILE_DMG), Weapon(NUKE_PIC, NUKE_DMG)	};

	*/

	Player poutine(PLAYER_PIC,Point(0,0),Rectangle(),5);
	poutine.scale(0.2,0.2);
	poutine.move(100,100);
	
	
	//Global game
	gSTATE gameStatus = inMenu;
	
	Material menuBackground(MENU_BG_PIC);
	Material menuTopBorder(MENU_TOP_BORDER_PIC);
	Material menuBotBorder(MENU_BOT_BORDER_PIC);
	Material menuLeftBorder(MENU_LEFT_BORDER_PIC);
	Material menuRightBorder(MENU_RIGHT_BORDER_PIC);
	
	Menu mainMenu(10,10,500,500);
	mainMenu.setBackground(menuBackground);
	mainMenu.setBotBorder(menuBotBorder);
	mainMenu.setTopBorder(menuTopBorder);
	mainMenu.setLeftBorder(menuLeftBorder);
	mainMenu.setRightBorder(menuRightBorder);
	
	
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
				mainMenu.draw(window);
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

