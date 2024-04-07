KeyHandler.o: KeyHandler.cpp KeyHandler.h
	g++ -c KeyHandler.cpp
Player.o: Player.cpp Player.h KeyHandler.h
	g++ -c Player.cpp
main.o: main.cpp KeyHandler.h Player.h
	g++ -c main.cpp
main: KeyHandler.o Player.o main.o
	g++ main.o KeyHandler.o Player.o -o main