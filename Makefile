KeyHandler.o: KeyHandler.cpp KeyHandler.h
	g++ -c KeyHandler.cpp
main.o: main.cpp KeyHandler.h
	g++ -c main.cpp
main: KeyHandler.o main.o
	g++ main.o KeyHandler.o -o main