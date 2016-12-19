
#ifndef CLASS_MATERIAL_HPP
#define CLASS_MATERIAL_HPP

#include <SFML/Graphics.hpp>
//#include <iostream>

class Material : public sf::Sprite
{
	private:
		sf::Texture* texture;
		
		int x;
		int y;
		
	public:
		Material();
		Material(std::string path,bool smooth=true);
	
		/**
		 * Draw the material in a window
		 * @param window
		 */
		void draw(sf::RenderWindow& window);
	
	
		/**
		 * Move the material by increasing the location by x
		 * @param x
		 */
		 void moveX(int x);
		 
		 
		/**
		 * Move the material by increasing the location by y
		 * @param y
		 */
		 void moveY(int y);
		 
		 
		/**
		 * Move the material by increasing the location by x and y
		 * @param x
		 * @param y
		 */
		 void move(int x=0,int y=0);
		 
		 /**
		  * Set the X coordinate to a value
		  * @param x
		  */
		 void setX(int x);
		 
		 
		 /**
		  * Set the Y coordinate to a value
		  * @param y
		  */
		 void setY(int y);
};


#endif


