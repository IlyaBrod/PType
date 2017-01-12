#include "MainMenu.hpp"



MainMenu::MainMenu(const int &width,const int &height) : Menu(width,height)
{
	play = Button(50,50,MENU_BUTTON);
	score = Button(100,100,MENU_BUTTON);
	option = Button(200,200,MENU_BUTTON);
	splash = Material(SPLASH_PIC);
}


MainMenu::MainMenu(const int &xo,const int &yo,const int &width,const int &height) : Menu(xo,yo,width,height)
{
	play = Button(xo,yo,MENU_BUTTON);
	score = Button(xo,yo,MENU_BUTTON);
	option = Button(xo,yo,MENU_BUTTON);
	splash = Material(SPLASH_PIC);
}


void MainMenu::draw(sf::RenderWindow& window)
{
	play.refresh();
	option.refresh();
	score.refresh();
	Menu::draw_1(window);
	
	play.draw(window);
	option.draw(window);
	score.draw(window);
	splash.draw(window);
	Menu::draw_2(window);
	
}


void MainMenu::setBackground(Material obj)
{
	Menu::setBackground(obj);
	
	play.setScale(scaleFactors[0],scaleFactors[1]);
	score.setScale(scaleFactors[0],scaleFactors[1]);
	option.setScale(scaleFactors[0],scaleFactors[1]);
	splash.setScale(scaleFactors[0],scaleFactors[1]);
	
	play.setPosition(origine.getX()+width/2+width/4-play.getWidth()/2,origine.getY()+height/4);
	score.setPosition(origine.getX()+width/2+width/5-play.getWidth()/2,origine.getY()+height/2);
	option.setPosition(origine.getX()+width/2+width/6-play.getWidth()/2,origine.getY()+3*height/4);
	splash.setPosition(origine.getX(),origine.getY());
	
}



bool MainMenu::isPlay()
{
	return play.pressed;
}

bool MainMenu::isOption()
{
	return option.pressed;
}

bool MainMenu::isScore()
{
	return score.pressed;
}

void MainMenu::exit()
{
	Menu::exit();
	play.pressed=false;
	score.pressed=false;
	option.pressed=false;
}

void MainMenu::update()
{
	play.refresh();
	score.refresh();
	option.refresh();
}
