#include "Menu.hpp"



Menu::Menu(const int &width,const int &height)
{
	origine = Point(0,0);
	this -> width = width;
	this -> height = height;
	
}
Menu::Menu(const int &xo,const int &yo,const int &width,const int &height)
{
	origine = Point(xo,yo);
	this -> width = xo+width;
	this -> height = yo+height;
	
}

void Menu::setBackground(Material obj)
{
	background = obj;
	background.setPosition(origine.getX(),origine.getY());
	background.setTextureRect(sf::IntRect(origine.getX(),origine.getY(),width,height));
}

void Menu::setLeftBorder(Material border)
{
	leftBorder = border;
	sf::FloatRect boundary = leftBorder.getGlobalBounds();
	leftBorder.setPosition(origine.getX(),origine.getY()+boundary.height/2);
}


void Menu::setRightBorder(Material border)
{
	rightBorder = border;
	sf::FloatRect boundary = rightBorder.getGlobalBounds();
	rightBorder.setPosition(origine.getX()+width-boundary.width,origine.getY()+boundary.height/2);
	
}

void Menu::setTopBorder(Material border)
{
	topBorder = border;
	sf::FloatRect boundary = topBorder.getGlobalBounds();
	topBorder.setPosition(origine.getX()+boundary.width/2,origine.getY());
}

void Menu::setBotBorder(Material border)
{
	botBorder = border;
	sf::FloatRect boundary = botBorder.getGlobalBounds();
	botBorder.setPosition(origine.getX()+boundary.width/2,origine.getY()+height-boundary.height);
}

void Menu::addObj(Material obj,LOCATION loc)
{
	objList.push_back(obj);
	objLoc.push_back(loc);
	
}
		
void Menu::draw(sf::RenderWindow& window)
{
	if(visible==true)
	{
		background.draw(window);
		leftBorder.draw(window);
		rightBorder.draw(window);
		topBorder.draw(window);
		botBorder.draw(window);
		
		if(objList.size()!=0)
		{
			for(int i=0;i<objList.size();i++)
			{
				objList[i].draw(window);
			}
		}
	}
}

void Menu::exit() 
{
	visible=false;
}
