#include "Material.hpp"

Material::Material()
{
	texture.create(10, 10);
	sf::Uint8* pixels = new sf::Uint8[10 * 10 * 4];
	texture.update(pixels);
	sprite = sf::Sprite();
	sprite.setTexture(texture);
	
	
}

Material::Material(std::string path,bool smooth)
{
	if(!texture.loadFromFile(path))
	{
		texture.create(10, 10);
		sf::Uint8* pixels = new sf::Uint8[10 * 10 * 4];
		texture.update(pixels);
	}
	
	if(smooth==true) texture.setSmooth(true);
	
	sprite = sf::Sprite();
	sprite.setTexture(texture);
	
}


void Material::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	
}

/*sf::Sprite* newSprite(std::string path)
{
	sf::Texture texture ;

	if (!texture.loadFromFile(path))
	{
		texture.create(10, 10);
		sf::Uint8* pixels = new sf::Uint8[10 * 10 * 4];
		texture.update(pixels);
	}
	texture.setSmooth(true);

	sf::Sprite *sprite = new sf::Sprite();
	sprite->setTexture(texture);

	return sprite;
}

*/

