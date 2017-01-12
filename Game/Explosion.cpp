#include "Explosion.hpp"

Explosion::Explosion(){
    ticks = 20 ;
}

Explosion::Explosion(std::string texturePath, const Point &origine, const sf::IntRect &box, const bool &solid, const bool &visible, const int _tick):
    Object(texturePath, origine, box, solid, visible), ticks(_tick){
}

void Explosion::inCollide(Object* obj){

}
