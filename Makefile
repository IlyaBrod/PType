
LD = g++
CC = g++
EXEC = Ptype
all : $(EXEC)

PType : Rectangle.o generalFunctions.o Object.o Point.o Unit.o 
	g++ Rectangle.o generalFunctions.o Object.o Point.o Unit.o -o Ptype-app -lsfml-graphics -lsfml-window -lsfml-system 

Rectangle.o: Rectangle.cpp Rectangle.hpp
	g++ -c Rectangle.cpp-oRectangle.o

generalFunctions.o: generalFunctions.cpp generalFunctions.hpp
	g++ -c generalFunctions.cpp-ogeneralFunctions.o

Object.o: Object.cpp Object.hpp
	g++ -c Object.cpp-oObject.o

Point.o: Point.cpp Point.hpp
	g++ -c Point.cpp-oPoint.o

Unit.o: Unit.cpp Unit.hpp
	g++ -c Unit.cpp-oUnit.o



clean : 
	rm -rf *.o
	
cleanAll :
	rm -rf *.o
	rm -rf $(EXEC)
