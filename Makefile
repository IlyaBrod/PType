
LD = g++
CC = g++
EXEC = PType
all : $(EXEC)

PType : Basic/Rectangle.o Basic/generalFunctions.o Basic/Material.o Basic/Point.o Interface/MainMenu.o Interface/Menu.o Interface/Interface.o Interface/Button.o Game/Bullet.o Game/Weapon.o Game/Object.o Game/Item.o Game/Player.o Game/Decor.o Game/Unit.o Game/Enemy.o Game/Explosion.o main.o 
	g++ Basic/Rectangle.o Basic/generalFunctions.o Basic/Material.o Basic/Point.o Interface/MainMenu.o Interface/Menu.o Interface/Interface.o Interface/Button.o Game/Bullet.o Game/Weapon.o Game/Object.o Game/Item.o Game/Player.o Game/Decor.o Game/Unit.o Game/Enemy.o Game/Explosion.o main.o -o Ptype-app -lsfml-graphics -lsfml-window -lsfml-system 

main.o: main.cpp Basic/Rectangle.hpp Basic/generalFunctions.hpp Basic/Material.hpp Basic/Point.hpp Interface/MainMenu.hpp Interface/Menu.hpp Interface/Interface.hpp Interface/Button.hpp Game/Bullet.hpp Game/Weapon.hpp Game/Object.hpp Game/Item.hpp Game/Player.hpp Game/Decor.hpp Game/Unit.hpp Game/Enemy.hpp Game/Explosion.hpp
	g++ -c main.cpp -o main.o

Basic/Rectangle.o: Basic/Rectangle.cpp Basic/Rectangle.hpp
	g++ -c Basic/Rectangle.cpp -o Basic/Rectangle.o

Basic/generalFunctions.o: Basic/generalFunctions.cpp Basic/generalFunctions.hpp
	g++ -c Basic/generalFunctions.cpp -o Basic/generalFunctions.o

Basic/Material.o: Basic/Material.cpp Basic/Material.hpp
	g++ -c Basic/Material.cpp -o Basic/Material.o

Basic/Point.o: Basic/Point.cpp Basic/Point.hpp
	g++ -c Basic/Point.cpp -o Basic/Point.o

Interface/MainMenu.o: Interface/MainMenu.cpp Interface/MainMenu.hpp
	g++ -c Interface/MainMenu.cpp -o Interface/MainMenu.o

Interface/Menu.o: Interface/Menu.cpp Interface/Menu.hpp
	g++ -c Interface/Menu.cpp -o Interface/Menu.o

Interface/Interface.o: Interface/Interface.cpp Interface/Interface.hpp
	g++ -c Interface/Interface.cpp -o Interface/Interface.o

Interface/Button.o: Interface/Button.cpp Interface/Button.hpp
	g++ -c Interface/Button.cpp -o Interface/Button.o

Game/Bullet.o: Game/Bullet.cpp Game/Bullet.hpp
	g++ -c Game/Bullet.cpp -o Game/Bullet.o

Game/Weapon.o: Game/Weapon.cpp Game/Weapon.hpp
	g++ -c Game/Weapon.cpp -o Game/Weapon.o

Game/Object.o: Game/Object.cpp Game/Object.hpp
	g++ -c Game/Object.cpp -o Game/Object.o

Game/Item.o: Game/Item.cpp Game/Item.hpp
	g++ -c Game/Item.cpp -o Game/Item.o

Game/Player.o: Game/Player.cpp Game/Player.hpp
	g++ -c Game/Player.cpp -o Game/Player.o

Game/Decor.o: Game/Decor.cpp Game/Decor.hpp
	g++ -c Game/Decor.cpp -o Game/Decor.o

Game/Unit.o: Game/Unit.cpp Game/Unit.hpp
	g++ -c Game/Unit.cpp -o Game/Unit.o

Game/Enemy.o: Game/Enemy.cpp Game/Enemy.hpp
	g++ -c Game/Enemy.cpp -o Game/Enemy.o

Game/Explosion.o: Game/Explosion.cpp Game/Explosion.hpp
	g++ -c Game/Explosion.cpp -o Game/Explosion.o



clean : 
	 rm *.o 
	 rm ./Basic/*.o 
	 rm ./Interface/*.o 
	 rm ./Game/*.o 
	 rm ./Config/*.o 
	 rm ./Images/*.o 


cleanAll :
	 rm *.o 
	 rm ./Basic/*.o 
	 rm ./Interface/*.o 
	 rm ./Game/*.o 
	 rm ./Config/*.o 
	 rm ./Images/*.o 

	rm -rf $(Ptype-app)
