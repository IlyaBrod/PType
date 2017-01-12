
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
	Button();
	Button(std::string path);
	Button(int x,int y,std::string path);
	
	/**
	 * Verify if the button is pressed
	 */
	void refresh();
	
	/**
	 * Redefinition of setScale Sprite function
	 */
	void setScale(float factorX, float factorY);
	
	/**
	 * Set the position of the button
	 */
	void setPosition(int x, int y);
	
	/**
	 * Return button dimensions
	 */
	int getWidth();
	int getHeight();
};





#endif
