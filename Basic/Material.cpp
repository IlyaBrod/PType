#include "Material.hpp"

Material::Material()
{
	texture = new sf::Texture();
	texture -> create(10, 10);
	sf::Uint8* pixels = new sf::Uint8[10 * 10 * 4];
	texture -> update(pixels);
	
	this -> setTexture(*texture);
	
	
}

Material::Material(std::string path,bool smooth)
{
	texture = new sf::Texture();
	
	if(!(texture->loadFromFile(path)))
	{
		texture -> create(10, 10);
		sf::Uint8* pixels = new sf::Uint8[10 * 10 * 4];
		texture->update(pixels);
	}
	
	if(smooth==true) texture->setSmooth(true);
	
	this -> setTexture(*texture);
	
}


void Material::draw(sf::RenderWindow& window)
{
	window.draw(*this);
	
}


