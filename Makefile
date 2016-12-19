
LD = g++
CC = g++
EXEC = PType
all : $(EXEC)

PType : Rectangle.o Bullet.o Weapon.o generalFunctions.o main.o Object.o Item.o Material.o Point.o Player.o Decor.o Unit.o Enemy.o Explosion.o 
	g++ Rectangle.o Bullet.o Weapon.o generalFunctions.o main.o Object.o Item.o Material.o Point.o Player.o Decor.o Unit.o Enemy.o Explosion.o -o Ptype-app -lsfml-graphics -lsfml-window -lsfml-system 

main.o: main.cpp Rectangle.hpp Bullet.hpp Weapon.hpp generalFunctions.hpp Object.hpp Item.hpp Material.hpp Point.hpp Player.hpp Decor.hpp Unit.hpp Enemy.hpp Explosion.hpp
	g++ -c main.cpp -o main.o

Rectangle.o: Rectangle.cpp Rectangle.hpp
	g++ -c Rectangle.cpp -o Rectangle.o

Bullet.o: Bullet.cpp Bullet.hpp
	g++ -c Bullet.cpp -o Bullet.o

Weapon.o: Weapon.cpp Weapon.hpp
	g++ -c Weapon.cpp -o Weapon.o

generalFunctions.o: generalFunctions.cpp generalFunctions.hpp
	g++ -c generalFunctions.cpp -o generalFunctions.o

Object.o: Object.cpp Object.hpp
	g++ -c Object.cpp -o Object.o

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp -o Item.o

Material.o: Material.cpp Material.hpp
	g++ -c Material.cpp -o Material.o

Point.o: Point.cpp Point.hpp
	g++ -c Point.cpp -o Point.o

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp -o Player.o

Decor.o: Decor.cpp Decor.hpp
	g++ -c Decor.cpp -o Decor.o

Unit.o: Unit.cpp Unit.hpp
	g++ -c Unit.cpp -o Unit.o

Enemy.o: Enemy.cpp Enemy.hpp
	g++ -c Enemy.cpp -o Enemy.o

Explosion.o: Explosion.cpp Explosion.hpp
	g++ -c Explosion.cpp -o Explosion.o



clean : 
	rm -rf *.o
	
cleanAll :
	rm -rf *.o
	rm -rf $(Ptype-app)
