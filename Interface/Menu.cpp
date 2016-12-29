#include "Menu.hpp"



Menu::Menu(const int &width,const int &height)
{
	origine = Point(0,0);
	this -> width = width;
	this -> height = height;
	
	scaleFactors = new float[2];
	scaleFactors[0] = 1.0;
	scaleFactors[1] = 1.0;
}
Menu::Menu(const int &xo,const int &yo,const int &width,const int &height)
{
	origine = Point(xo,yo);
	this -> width = xo+width;
	this -> height = yo+height;
	
	scaleFactors = new float[2];
	scaleFactors[0] = 1.0;
	scaleFactors[1] = 1.0;
	
}

void Menu::setBackground(Material obj)
{
	background = obj;
	int SCREEN[2] = {width,height};
	background.adaptSize(SCREEN);
	scaleFactors = background.getSizeFactor();
	
	background.setPosition(origine.getX(),origine.getY());
}

void Menu::setLeftBorder(Material border)
{
	leftBorder = border;
	sf::FloatRect boundary = leftBorder.getGlobalBounds();
	leftBorder.setPosition(origine.getX()-boundary.width/6,origine.getY());
	//leftBorder.setTextureRect(sf::IntRect(origine.getX(),origine.getY(),boundary.width,background.getTextureHeight()));
}


void Menu::setRightBorder(Material border)
{
	rightBorder = border;
	sf::FloatRect boundary = rightBorder.getGlobalBounds();
	rightBorder.setPosition(origine.getX()+background.getTextureWidth()-boundary.width/6,origine.getY());
	//rightBorder.setTextureRect(sf::IntRect(origine.getX(),origine.getY(),boundary.width,background.getTextureHeight()));
}

void Menu::setTopBorder(Material border)
{
	topBorder = border;
	topBorder.setScale(scaleFactors[0],scaleFactors[1]);
	sf::FloatRect boundary = topBorder.getGlobalBounds();
	topBorder.setPosition(origine.getX(),origine.getY()-boundary.height/6);
	//topBorder.setTextureRect(sf::IntRect(origine.getX(),origine.getY(),background.getTextureWidth(),boundary.height));
}

void Menu::setBotBorder(Material border)
{
	botBorder = border;
	sf::FloatRect boundary = botBorder.getGlobalBounds();
	botBorder.setPosition(origine.getX(),origine.getY()+background.getTextureHeight()-boundary.height/6);
	//botBorder.setTextureRect(sf::IntRect(origine.getX(),origine.getY(),background.getTextureWidth(),boundary.height));
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
