
#ifndef CLASS_MATERIAL_HPP
#define CLASS_MATERIAL_HPP

#include <SFML/Graphics.hpp>
//#include <iostream>
class Material
{
	private:
		sf::Texture* texture;
		sf::Sprite sprite;
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


