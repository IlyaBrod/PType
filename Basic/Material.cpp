#include "Material.hpp"

Material::Material()
{
	texture = new sf::Texture();
	texture -> create(10, 10);
	sf::Uint8* pixels = new sf::Uint8[10 * 10 * 4];
	texture -> update(pixels);

	this -> setTexture(*texture);

	scaleFactors = new float[2];

}

 Material::~Material() {}

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

	scaleFactors = new float[2];

}

Material::Material(std::string path,int screen[2], bool smooth)
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

	adaptSize(screen);

	scaleFactors = new float[2];

}

void Material::mat_setX(int x)
{
	this->x=x;
	Sprite::setPosition(x,this->y);
}
void Material::mat_setY(int y)
{
	this->x=x;
	Sprite::setPosition(this->x,y);
}

float Material::mat_getX()
{
	 sf::Vector2f vec = getPosition();
	 return vec.x;
}

float Material::mat_getY()
{
	 sf::Vector2f vec = getPosition();
	 return vec.y;
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
	scaleFactors[0] = (float)screen[0]/getTextureWidth();
	scaleFactors[1] = (float)screen[1]/getTextureHeight();
	this->setScale(scaleFactors[0],scaleFactors[1]);
}

float* Material::getSizeFactor()
{
	return scaleFactors;
}

void Material::setScale(float factorX,float factorY)
{
	sf::Sprite::setScale(factorX,factorY);
}
