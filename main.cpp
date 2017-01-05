
#include <SFML/Window.hpp>
#include <iostream>


#include "Game/Player.hpp"
#include "Game/Weapon.hpp"

#include "Basic/generalFunctions.hpp"
#include "Basic/Material.hpp"

#include "Interface/Menu.hpp"
#include "Interface/Button.hpp"

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
	
	int SCREEN[2] = {1366,768};
	
	
	Material mainMenuBackground(MENU_BG_PIC);
	Material mainMenuTopBorder(MENU_TOP_BORDER_PIC);
	Material mainMenuBotBorder(MENU_BOT_BORDER_PIC);
	Material mainMenuLeftBorder(MENU_LEFT_BORDER_PIC);
	Material mainMenuRightBorder(MENU_RIGHT_BORDER_PIC);
	
	Menu mainMenu(0,0,SCREEN[0],SCREEN[1]);
	mainMenu.setBackground(mainMenuBackground);
	mainMenu.setBotBorder(mainMenuBotBorder);
	mainMenu.setTopBorder(mainMenuTopBorder);
	mainMenu.setLeftBorder(mainMenuLeftBorder);
	mainMenu.setRightBorder(mainMenuRightBorder);
	
	Material scoreMenuBackground(MENU_BG_PIC);
	Material scoreMenuTopBorder(MENU_TOP_BORDER_PIC);
	Material scoreMenuBotBorder(MENU_BOT_BORDER_PIC);
	Material scoreMenuLeftBorder(MENU_LEFT_BORDER_PIC);
	Material scoreMenuRightBorder(MENU_RIGHT_BORDER_PIC);
	
	Menu scoreMenu(SCREEN[0]/2-200,SCREEN[1]/2-200,100,100);
	scoreMenu.setBackground(scoreMenuBackground);
	scoreMenu.setBotBorder(scoreMenuBotBorder);
	scoreMenu.setTopBorder(scoreMenuTopBorder);
	scoreMenu.setLeftBorder(scoreMenuLeftBorder);
	scoreMenu.setRightBorder(scoreMenuRightBorder);
	
	//mainMenu.setVisible();
	
	sf::RenderWindow window(sf::VideoMode(SCREEN[0], SCREEN[1]), "P-Type",sf::Style::Fullscreen);//,sf::Style::Fullscreen

	/**
	 * TEST ZONE
	 */
	 Button mainMenuExit(10,10,BUTTON_EXIT);
	 //mainMenuExit.setScale(0.5,0.5);
	 mainMenu.setExitButton(mainMenuExit);

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
        
        if(mainMenu.isVisible()==false)
        {
			gameStatus=inExit;
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
				mainMenu.draw(window);
				scoreMenu.draw(window);
				break;
				
			case(inGame):
				poutine.draw(window);
				break;
				
			case(inPause):
				break;
				
			default:
				break;
		}
		
        window.display();
    }

	
	return 0 ;
}

