#include "Menu.hpp"



Menu::Menu(const int &width,const int &height)
{
	origine = Point(0,0);
	this -> width = width;
	this -> height = height;
	
	scaleFactors = new float[2];
	scaleFactors[0] = 1.0;
	scaleFactors[1] = 1.0;
	
	setVisible();
}
Menu::Menu(const int &xo,const int &yo,const int &width,const int &height)
{
	origine = Point(xo,yo);
	this -> width = xo+width;
	this -> height = yo+height;
	
	scaleFactors = new float[2];
	scaleFactors[0] = 1.0;
	scaleFactors[1] = 1.0;
	
	setVisible();
	
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
	leftBorder.setScale(scaleFactors[0],scaleFactors[1]);
	sf::FloatRect boundary = leftBorder.getGlobalBounds();
	leftBorder.setPosition(origine.getX()-boundary.width/6,origine.getY());
}


void Menu::setRightBorder(Material border)
{
	rightBorder = border;
	rightBorder.setScale(scaleFactors[0],scaleFactors[1]);
	sf::FloatRect boundary = rightBorder.getGlobalBounds();
	rightBorder.setPosition(origine.getX()+width-5*boundary.width/6,origine.getY());
}

void Menu::setTopBorder(Material border)
{
	topBorder = border;
	topBorder.setScale(scaleFactors[0],scaleFactors[1]);
	sf::FloatRect boundary = topBorder.getGlobalBounds();
	topBorder.setPosition(origine.getX(),origine.getY()-boundary.height/6);
	
}

void Menu::setBotBorder(Material border)
{
	botBorder = border;
	botBorder.setScale(scaleFactors[0],scaleFactors[1]);
	sf::FloatRect boundary = botBorder.getGlobalBounds();
	botBorder.setPosition(origine.getX(),origine.getY()+height-5*boundary.height/6);
	
}

void Menu::setExitButton(Button knopka)
{
	exitButton=knopka;
	exitButton.setScale(scaleFactors[0],scaleFactors[1]);
	sf::FloatRect boundary = background.getGlobalBounds();
	exitButton.setPosition(boundary.width-exitButton.width+background.getPosition().x,background.getPosition().y);
}

void Menu::addObj(Material obj,LOCATION loc)
{
	objList.push_back(obj);
	objLoc.push_back(loc);
	
}
		
void Menu::draw(sf::RenderWindow& window)
{
	if(exitButton.pressed==true)
	{
		exit();
	}
	if(visible==true)
	{
		background.draw(window);
		leftBorder.draw(window);
		rightBorder.draw(window);
		topBorder.draw(window);
		botBorder.draw(window);
		exitButton.draw(window);
		exitButton.refresh();
		
		if(objList.size()!=0)
		{
			for(int i=0;i<objList.size();i++)
			{
				objList[i].draw(window);
			}
		}
	}
}

void Menu::setVisible()
{
	visible=true;
}

void Menu::exit() 
{
	visible=false;
}

bool Menu::isVisible()
{
	return visible;
}
