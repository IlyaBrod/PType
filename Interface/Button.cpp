#include "Button.hpp"


Button::Button()
{
	mouseRec = Rectangle();
	pressed=false;
	mouseRec.setH(5);
	mouseRec.setW(5);
}

Button::Button(int x, int y, int width, int height)
{
	setH(height);
	setW(width);
	setX(x);
	setY(y);
	mouseRec.setH(5);
	mouseRec.setW(5);
	pressed=false;
}

void Button::refresh()
{
	sf::Vector2i vec = getPosition();
	
	mouseRec.setX(vec.x);
	mouseRec.setY(vec.y);
	
	if(intersect(mouseRec)==true)
	{
		event=true;
	}
}
