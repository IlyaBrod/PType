
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
	
};


#endif


