
#ifndef CLASS_MATERIAL_HPP
#define CLASS_MATERIAL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Material : public sf::Sprite
{
	private:
		sf::Texture* texture;
		
		int x;
		int y;
		
		float* scaleFactors;
		
	public:
		Material();
		Material(std::string path,bool smooth=true);
		Material(std::string path,int screen[2],bool smooth=true);
	
		float mat_getX();
		float mat_getY();
	
		/**
		 * Draw the material in a window
		 * @param window
		 */
		void draw(sf::RenderWindow& window);
		
		/**
		 * Print texture size Heigh x Width
		 */
		void printTextureSize();
		 
		 /**
		  * Give the texture dimensions
		  */
		int getTextureWidth();
		int getTextureHeight();
		 
		 /**
		  * Adapt textures to the screen
		  * @param screen[2] Table of screen [Width,Height]
		  * @return table[2] Factors of adaptation
		  */
		void adaptSize(int screen[2]);
		
		/**
		 * Get size daptation factors
		 * @return table[2] Factors of adaptation
		 */
		float* getSizeFactor();
		
		/**
		 * Sprite setScale method
		 */
		void setScale(float factorX,float factorY);
	
};


#endif


