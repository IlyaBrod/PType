#include "Game.hpp"

Game::Game(){
    tick=0;
    loadLevel("level1.txt");
	scaleFactor = new float[2];
	scaleFactor[0] = 1;
	scaleFactor[1] = 1;

	background = new Material[2];
	background[0] = Material(GAME_BACKGROUND);
	background[1] = Material(GAME_BACKGROUND);
	background[0].setPosition(0,0);
	background[1].setPosition(SCREENW,0);

	Player* poutine = new Player(PLAYER_PIC,Point(0,0), sf::IntRect(),16);
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
	background[0].draw(window);
	background[1].draw(window);
	backgroundMove();
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
	
	background[0].setScale(scaleFactor[0],scaleFactor[1]);
	background[1].setScale(scaleFactor[0],scaleFactor[1]);
}


void Game::backgroundMove()
{
	if(background[0].mat_getX()==-SCREENW)
	{
		background[0].move(2*SCREENW,0);
	}
	if(background[1].mat_getX()==-SCREENW)
	{
		background[1].move(2*SCREENW,0);
	}
	
	background[0].move(-GAME_BACKGROUND_SPEED,0);
	background[1].move(-GAME_BACKGROUND_SPEED,0);
}

void Game::deleteObject(int i){
    //delete objects[i];
    objects.erase(objects.begin()+i);
}

void Game::autoMove()
{
	Object *pObj ;
	for(unsigned int i=0;i<objects.size();i++)
	{
		pObj = objects[i] ;
		
		switch(pObj->get_team()){
			case PBULLET:
				pObj->move(DEFAULT_BULLETSPEED,0);
				
				break ;
			case ENEMY :
				pObj->move(-ENEMY_SPEED, 0);
				break ;
		}
		if(pObj->getX() < -255 || pObj->getX() > SCREENW+255 || pObj->getY() < -128 || pObj->getY() > SCREENH+128)
			pObj-> set_alive(false);
		
		//pObj -> autoMove(STRAIGHT);
	}
	
}
