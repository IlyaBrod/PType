#ifndef CLASS_MAINMENU_HPP
#define CLASS_MAINMENU_HPP

#include "Menu.hpp"
#include "../Basic/Material.hpp"
#include "../Config/INTERFACE_CONFIG.hpp"
#include <SFML/Graphics.hpp>
//#include <iostream>

class MainMenu : public Menu
{
	private:
		Button play;
		Button option;
		Button score;
		Material splash;
		
	
	public:
		MainMenu(const int &width,const int &height);
		MainMenu(const int &xo,const int &yo,const int &width,const int &height);
		
		void draw(sf::RenderWindow& window);
		void setBackground(Material obj);
	
};



#endif
