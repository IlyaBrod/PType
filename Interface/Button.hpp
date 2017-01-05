
#ifndef CLASS_BUTTON_HPP
#define CLASS_BUTTON_HPP

#include "../Basic/Rectangle.hpp"
#include "../Basic/Material"
#include <SFML/Graphics.hpp>

class Button : public Material, public sf::Mouse, public Rectangle
{
	private:
	Rectangle mouseRec;
	bool pressed;
	
	public:
	
	Button();
	Button(int x,int y, int width, int height);
	
	/**
	 * Verify if the button is pressed
	 */
	void refresh();
	
	
	
	
	
};





#endif
