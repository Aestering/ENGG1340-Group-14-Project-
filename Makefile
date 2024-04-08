
main: Player.cpp main.cpp Player.h Game_Data.h Game.h Game.cpp Bot.h Bot.cpp
	g++ -pthread main.cpp Player.cpp Game.cpp Bot.cpp -o main