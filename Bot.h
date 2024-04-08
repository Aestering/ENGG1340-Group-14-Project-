#ifndef BOT_H
#define BOT_H
#include "Game_Data.h"
#include "Player.h"
#include <string>
#include <vector>
#include <pthread.h>

class Bot
{
private:
    Direction direction = West;
    bool running = true;
public:
    std::vector<int> x, y;
    int body = 3;
    Bot();
    void update_body();
    void update_direction(Player &player, int appleX, int appleY);
    bool check_apple(int, int);
    bool check_collision(Player& other);
    bool islegible(Player &player, int nextX, int nextY);
    void draw(std::string (&board)[HEIGHT]);
    ~Bot();
};
#endif