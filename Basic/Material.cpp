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

void Material::printTextureSize()
{
	sf::Vector2u siz = texture->getSize();
	std::cout << "Size : " <<siz.x<<"x"<<siz.y<<std::endl;
}

int Material::getTextureWidth()
{
	sf::Vector2u siz = texture->getSize();
	return siz.x;
}

int Material::getTextureHeight()
{	
	sf::Vector2u siz = texture->getSize();
	return siz.y;
}

void Material::adaptSize(int screen[2])
{
	this->setScale((float)screen[0]/getTextureWidth(),(float)screen[1]/getTextureHeight());	
}
