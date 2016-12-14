/*#include "generalFunctions.hpp"
#include "Rectangle.hpp"
#include "Object.hpp"
#include "Item.hpp"
#include "Bullet.hpp"
#include "Unit.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Explosion.hpp"
#include "Decor.hpp"*/
#include "WEAPON_CONFIG.hpp"
#include "Weapon.hpp"

using namespace std ;

int main(int argv, char** argc){

	const Weapon wpn_def[6] = {	Weapon(SHOVEL_PIC, SHOVEL_DMG)	, Weapon(VODKA_PIC, VODKA_DMG), 
								Weapon(GUN_PIC, GUN_DMG)		, Weapon(LASER_PIC, LASER_DMG),
								Weapon(MISSILE_PIC, MISSILE_DMG), Weapon(NUKE_PIC, NUKE_DMG)	};

	return 0 ;
}
