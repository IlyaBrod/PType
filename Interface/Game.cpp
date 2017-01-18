#include "Game.hpp"

Game::Game(){
    tick=0;
    loadLevel("level1.txt");
	scaleFactor = new float[2];
	scaleFactor[0] = 1;
	scaleFactor[1] = 1;

	Player* poutine = new Player(PLAYER_PIC,Point(0,0), sf::IntRect(),5);
	poutine->move(poutine->getTextureWidth(),poutine->getTextureHeight()*2);
	objects.push_back(poutine);



}

void Game::loadLevel(std::string path){
    //levelFile.open(path);
}

void Game::closeLevel(){
    //levelFile.close();
}

void Game::checkEvent()
{

}


void Game::draw(sf::RenderWindow& window)
{
	for(unsigned int i=0;i<objects.size();i++)
	{
		objects.at(i) -> draw(window);
	}
}

void Game::setScaleFactor(float* sf)
{
	scaleFactor[0] = sf[0];
	scaleFactor[1] = sf[1];

	for(unsigned int i=0;i<objects.size();i++)
	{
		objects.at(i) -> setScale(scaleFactor[0],scaleFactor[1]);
	}
}

void Game::deleteObject(int i){
    delete objects[i];
    objects.erase(objects.begin()+i);
}
