#include "Game.hpp"

Game::Game(){
    tick=0;
    loadLevel("level1.txt");

}

void Game::loadLevel(std::string path){
    levelFile.open(path);
}

void Game::closeLevel(){
    levelFile.close();
}

void checkEvent()
