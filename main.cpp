#include "generalFunctions.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"
#include "Object.hpp"
#include "Item.hpp"
#include "Bullet.hpp"
#include "Unit.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Explosion.hpp"
#include "Decor.hpp"

using namespace std ;

int main(int argv, char** argc){

	const Weapon wpn_def[6] = {	Weapon("wpn_shovel", SHOVEL_DMG)	, Weapon("wpn_vodka", VODKA_DMG), 
								Weapon("wpn_gun", GUN_DMG)			, Weapon("wpn_laser", LASER_DMG),
								Weapon("wpn_missile", MISSILE_DMG)	, Weapon("wpn_nuke", NUKE_DMG)	 };

	return 0 ;
}