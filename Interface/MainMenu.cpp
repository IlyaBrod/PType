#include "MainMenu.hpp"



MainMenu::MainMenu(const int &width,const int &height) : Menu(width,height)
{
	play = Button(50,50,MENU_BUTTON);
	score = Button(100,100,MENU_BUTTON);
	option = Button(200,200,MENU_BUTTON);
	splash = Material(SPLASH_PIC);
	
	loadText();
	
}


MainMenu::MainMenu(const int &xo,const int &yo,const int &width,const int &height) : Menu(xo,yo,width,height)
{
	play = Button(xo,yo,MENU_BUTTON);
	score = Button(xo,yo,MENU_BUTTON);
	option = Button(xo,yo,MENU_BUTTON);
	splash = Material(SPLASH_PIC);
	
	loadText();
}

void MainMenu::loadText()
{
	font = new sf::Font;
	font->loadFromFile(TEXT_FONT);
	
	text_play = sf::Text("Play",*font);
	text_play.setCharacterSize(60);
	text_play.setColor(sf::Color::White);
	
	text_option = sf::Text("Options",*font);
	text_option.setCharacterSize(60);
	text_option.setColor(sf::Color::White);
	
	text_score = sf::Text("Score",*font);
	text_score.setCharacterSize(60);
	text_score.setColor(sf::Color::White);
	
	text_score.setPosition(100,100);
	text_option.setPosition(200,200);
	text_play.setPosition(300,300);
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
	
	window.draw(text_play);
	window.draw(text_option);
	window.draw(text_score);
	
	
	Menu::draw_2(window);
	
}


void MainMenu::setBackground(Material obj)
{
	Menu::setBackground(obj);
	
	play.setScale(scaleFactors[0],scaleFactors[1]);
	score.setScale(scaleFactors[0],scaleFactors[1]);
	option.setScale(scaleFactors[0],scaleFactors[1]);
	splash.setScale(scaleFactors[0],scaleFactors[1]);
	
	text_play.setPosition(origine.getX()+width/2+width/4-play.getWidth()/10,origine.getY()+height/4+play.getHeight()/4);
	text_score.setPosition(origine.getX()+width/2+width/5-score.getWidth()/10,origine.getY()+height/2+score.getHeight()/4);
	text_option.setPosition(origine.getX()+width/2+width/6-option.getWidth()/10,origine.getY()+3*height/4+option.getHeight()/4);
	
	
	play.setPosition(origine.getX()+width/2+width/4-play.getWidth()/2,origine.getY()+height/4);
	score.setPosition(origine.getX()+width/2+width/5-play.getWidth()/2,origine.getY()+height/2);
	option.setPosition(origine.getX()+width/2+width/6-play.getWidth()/2,origine.getY()+3*height/4);
	splash.setPosition(origine.getX(),origine.getY());
	
}

bool MainMenu::isPlay()
{
	return play.isPressed();
}

bool MainMenu::isOption()
{
	return option.isPressed();
}

bool MainMenu::isScore()
{
	return score.isPressed();
}

void MainMenu::exit()
{
	Menu::exit();

}

void MainMenu::update()
{
	Menu::update();
	play.refresh();
	score.refresh();
	option.refresh();
}
