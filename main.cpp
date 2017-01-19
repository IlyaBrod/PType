
#include <SFML/Window.hpp>
#include <iostream>

#include "Basic/generalFunctions.hpp"
#include "Basic/Material.hpp"

#include "Interface/Menu.hpp"
#include "Interface/Button.hpp"
#include "Interface/MainMenu.hpp"

#include "Config/INTERFACE_CONFIG.hpp"
#include "Config/PLAYER_CONFIG.hpp"
#include "Config/WEAPON_CONFIG.hpp"
#include "Config/ENEMY_CONFIG.hpp"

#include "Interface/Game.hpp"
#include "Game/Enemy.hpp"

using namespace std ;

typedef enum {inMenu,inOption,inGame,inPause,inScore,inExit} gSTATE;


int main(int argv, char** argc){
    srand(time(NULL));

	//##################       INIT    	################################
	/*
	const Weapon wpn_def[6] = {	Weapon(SHOVEL_PIC, SHOVEL_DMG)	, Weapon(VODKA_PIC, VODKA_DMG),
								Weapon(GUN_PIC, GUN_DMG)		, Weapon(LASER_PIC, LASER_DMG),
								Weapon(MISSILE_PIC, MISSILE_DMG), Weapon(NUKE_PIC, NUKE_DMG)	};

	*/

	Game* game = new Game();


	//Global game
	gSTATE gameStatus = inMenu;

	int SCREEN[2] = {1366,768};


	//Imgs universelles aux menus
	Material menuBackground(MENU_BG_PIC);
	Material menuTopBorder(MENU_TOP_BORDER_PIC);
	Material menuBotBorder(MENU_BOT_BORDER_PIC);
	Material menuLeftBorder(MENU_LEFT_BORDER_PIC);
	Material menuRightBorder(MENU_RIGHT_BORDER_PIC);
	Button menuExit(10,10,BUTTON_EXIT);

	MainMenu mainMenu(0,0,SCREEN[0],SCREEN[1]);
	mainMenu.setBackground(menuBackground);
	mainMenu.setBotBorder(menuBotBorder);
	mainMenu.setTopBorder(menuTopBorder);
	mainMenu.setLeftBorder(menuLeftBorder);
	mainMenu.setRightBorder(menuRightBorder);
	mainMenu.setExitButton(menuExit);

	Menu scoreMenu(SCREEN[0]/2-200,SCREEN[1]/2-200,100,100);
	scoreMenu.setBackground(menuBackground);
	scoreMenu.setBotBorder(menuBotBorder);
	scoreMenu.setTopBorder(menuTopBorder);
	scoreMenu.setLeftBorder(menuLeftBorder);
	scoreMenu.setRightBorder(menuRightBorder);
	scoreMenu.setExitButton(menuExit);

	Menu gameMenu(0,0,SCREEN[0],SCREEN[1]);
	gameMenu.setBackground(menuBackground);
	gameMenu.setBotBorder(menuBotBorder);
	gameMenu.setTopBorder(menuTopBorder);
	gameMenu.setLeftBorder(menuLeftBorder);
	gameMenu.setRightBorder(menuRightBorder);
	gameMenu.setExitButton(menuExit);

	sf::RenderWindow window(sf::VideoMode(SCREEN[0], SCREEN[1]), "P-Type",sf::Style::Fullscreen);//,sf::Style::Fullscreen
	window.setFramerateLimit(60);
	/**
	 * TEST ZONE
	 */

	game -> setScaleFactor(gameMenu.getScaleFactor());

	gameMenu.exit();
	scoreMenu.exit();
	mainMenu.setVisible();

	bool comUp=false, comLeft=false, comDown=false, comRight=false;
	bool comShoot = false ;
	int vecSize;

	int fireTicks = 8;
	bool hasFired = false;

	int enemySpawn = 10;

	//##################	MAIN LOOP	################################
    while (gameStatus!=inExit) //window.isOpen()
    {


		//EVENTS
		///////////////////////////////////////////////
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
                gameStatus=inExit;
            }


			if (event.type == sf::Event::KeyPressed)
			{
				// MOVE ACTIVATE
				if (event.key.code == sf::Keyboard::Left){
					comLeft=true ;
				}
				if(event.key.code ==sf::Keyboard::Right){
					comRight = true ;
				}
				if(event.key.code ==sf::Keyboard::Up){
					comUp = true ;
				}
				if(event.key.code ==sf::Keyboard::Down){
					comDown = true ;
				}
				if(event.key.code ==sf::Keyboard::X){        //shoot command for player{
					comShoot = true ;
				}
			}
			else if(event.type == sf::Event::KeyReleased)
			{
				//MOVE RELEASE
				if (event.key.code ==sf::Keyboard::Left){
					comLeft=false ;
				}
				if(event.key.code ==sf::Keyboard::Right){
					comRight = false ;
				}
				if(event.key.code ==sf::Keyboard::Up){
					comUp = false ;
				}
				if(event.key.code ==sf::Keyboard::Down){
					comDown = false ;
				}
				if(event.key.code ==sf::Keyboard::X){    //shoot command for player
					comShoot = false ;
					hasFired = false ;
				}
			}
        }

        if(fireTicks>0)
            fireTicks--;
        //AFFECT MOVE
        if(comUp){
			game -> getObject(0) -> move(0,-Y_SPEED);
		}
		if(comDown){
			game -> getObject(0) -> move(0,Y_SPEED);
		}
		if(comLeft){
			game -> getObject(0) -> move(-X_SPEED,0);
		}
		if(comRight){
			game -> getObject(0) -> move(X_SPEED,0);
		}
		if(comShoot){
			if(fireTicks<=0 && hasFired == false){
			    hasFired = true ;
				fireTicks=8;
				game->addObject(game->getObject(0)->shoot());
			}
		}

		//ENEMY AUTO MOVE   ///////
		game-> autoMove();


		//ADD ENEMY
		enemySpawn--;
		if(enemySpawn<=0){
			enemySpawn=100;
			Enemy* br = new Enemy(ENEMY_BEAR);
			br -> setScale(gameMenu.getScaleFactor()[0],gameMenu.getScaleFactor()[1]);
			game->addObject(br);
		}

		//ENEMY AUTO SHOOT  ///////


        // COLISIONS //////////////
        vecSize = game->getNbObjects();
        for(int i = 0 ; i < vecSize ; i++){
            for(int j = i+1 ; j < vecSize ; j++){
                game->getObject(i)->collide(game->getObject(j));
            }
        }

        //CHECK ALIVE ///////////
        for(int i = vecSize-1 ; i >= 0 ; i--){
            if(game->getObject(i)->get_alive()==false){
                game->deleteObject(i);
                vecSize = game->getNbObjects();
            }
        }

        ///////////////////////////////////////////////

        if(mainMenu.isVisible()==false && gameStatus!=inGame){
			gameStatus=inExit;
		}


		//DISPLAY
		window.clear(sf::Color::Black);

		switch(gameStatus)
		{
			case(inMenu):							//main Menu
				if(mainMenu.isScore()){
					gameStatus=inScore;
					scoreMenu.setVisible();
				}
				else if(mainMenu.isOption()){
					//gameStatus=inOption;
				}
				else if(mainMenu.isPlay()){
					gameMenu.setVisible();
					mainMenu.exit();
					gameStatus=inGame;
				}
				mainMenu.draw(window);

				gameMenu.update();
				scoreMenu.update();
				break;

			case(inOption):							//Options
				break;

			case(inScore):							//Score

				if(scoreMenu.isVisible()==false) gameStatus=inMenu;
				mainMenu.draw(window);
				scoreMenu.draw(window);

				gameMenu.update();
				mainMenu.update();
				scoreMenu.update();
				break;

			case(inGame):							//Game
				if(gameMenu.isVisible()==false)
				{
					gameStatus=inMenu;
					mainMenu.setVisible();
				}
				gameMenu.draw_1(window);
				game -> draw(window);
				gameMenu.draw_2(window);

				gameMenu.update();
				mainMenu.update();
				scoreMenu.update();
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

