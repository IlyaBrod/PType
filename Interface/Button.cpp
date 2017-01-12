#include "Button.hpp"


Button::Button(){}

Button::Button(std::string path) : Material(path)
{
	lock=false;
	pressed=false;
	sf::FloatRect boundary = sf::Sprite::getGlobalBounds();
	width = boundary.width;
	height = boundary.height;
}

Button::Button(int x, int y,std::string path) : Material(path), sf::IntRect(x,y,width,height)
{
	lock=false;
	pressed=false;
	sf::FloatRect boundary = sf::Sprite::getGlobalBounds();
	width = boundary.width;
	height = boundary.height;
	sf::Sprite::setPosition(x,y);
}


void Button::refresh()
{
	sf::Vector2i vec = sf::Mouse::getPosition();
	
	if(contains(vec)==true && sf::Mouse::isButtonPressed(sf::Mouse::Left)==true && lock==false)
	{
		lock=true;
		pressed=false;
	}
	else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)==false && lock==true)
	{
		lock=false;
		pressed=true;
	}
	else
	{
		pressed=false;
	}
}

void Button::setScale(float factorX, float factorY)
{
	sf::Sprite::setScale(factorX,factorY);
	sf::FloatRect boundary = sf::Sprite::getGlobalBounds();
	width = boundary.width;
	height = boundary.height;
}


void Button::setPosition(int x, int y)
{
	sf::Sprite::setPosition(x,y);
	left = x;
	top = y;
}

int Button::getHeight()
{
	return height;
}

int Button::getWidth()
{
	return width;
}
