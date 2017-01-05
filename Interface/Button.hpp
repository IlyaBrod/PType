
#ifndef CLASS_BUTTON_HPP
#define CLASS_BUTTON_HPP

#include "../Basic/Rectangle.hpp"
#include "../Basic/Material.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public Material, public sf::Mouse, public sf::IntRect
{
	
	public:
	bool pressed;
	Button(std::string path);
	Button(int x,int y, int width, int height,std::string path);
	
	/**
	 * Verify if the button is pressed
	 */
	void refresh();
	
	
	
	
	
};





#endif