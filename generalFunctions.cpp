#include "generalFunctions.hpp"

bool min(const int &a, const int &b){
	return (a<b)? a : b ;
}

bool max(const int &a, const int &b){
	return (a<b)? b : a ;
}

sf::Sprite* newSprite(std::string path)
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
