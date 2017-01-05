#include "Button.hpp"


Button::Button(std::string path) : Material(path)
{
	pressed=false;
}

Button::Button(int x, int y, int width, int height,std::string path) : Material(path), sf::IntRect(x,y,width,height)
{
	pressed=false;
	sf::Sprite::move(x,y);
}

void Button::refresh()
{
	sf::Vector2i vec = sf::Mouse::getPosition();
	
	if(contains(vec)==true && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		pressed=true;
		std::cout << "PRESSED : " << pressed << std::endl;
	}
}
