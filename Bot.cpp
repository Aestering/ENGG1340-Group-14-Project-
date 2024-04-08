#include <iostream>
#include <pthread.h>
#include <vector>
#include <utility>
#include <algorithm>
#include "Bot.h"
#include "Player.h"
#include "Game_Data.h"

Bot::Bot(){
    x.resize(100, -1);
    y.resize(100, -1);
    x[0] = 1;
    y[0] = 52;
}
Bot::~Bot(){

}

void Bot::update_direction(Player &player, int appleX, int appleY) {
    int botX = x[0];
    int botY = y[0];

    int distanceX = appleX - botX;
    int distanceY = appleY - botY;

    int nextX = botX + (distanceX > 0 ? 1 : -1); 
    int nextY = botY + (distanceY > 0 ? 1 : -1); 

    if (abs(distanceX) > abs(distanceY)) {

        if (nextX >= 0 && nextX < HEIGHT && !islegible(player, nextX, botY)) {
            this->direction = (distanceX > 0 ? South : North);
        } else if (nextY >= 0 && nextY < HEIGHT && !islegible(player, botX, nextY)) {
            this->direction = (distanceY > 0 ? East : West);
        }
    } else {

        if (nextY >= 0 && nextY < WIDTH && !islegible(player, botX, nextY)) {
            this->direction = (distanceY > 0 ? East : West);
        } else if (nextX >= 0 && nextX < WIDTH && !islegible(player, nextX, botY)) {
            this->direction = (distanceX > 0 ? South : North);
        }
    }
}
void Bot::update_body(){
    for(int i = body; i > 0; i--){
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    } 
    if(direction == West){
        y[0]--;
    }
    if(direction == East){
        y[0]++;
    }
    if(direction == North){
        x[0]--;
    }
    if(direction == South){
        x[0]++;
    }
    if(x[0] >= HEIGHT - 1) x[0] = 1; 
    if(x[0] <= 0) x[0] = HEIGHT - 2;
    if(y[0] >= WIDTH - 1) y[0] = 1; 
    if(y[0] <= 0) y[0] = WIDTH - 2;
}
bool Bot::check_apple(int appleX, int appleY){
    if(x[0] == appleX && y[0] == appleY){
        body++;
        return true;
    }

    return false;
}
bool Bot::check_collision(Player &other){
    for(int i = 4; i < body; i++){
       if(x[0] == x[i] && x[0] == y[i]) return true;
    }
    for(int i = 0; i < other.body; i++){
       if(x[0] == other.x[i] && y[0] == other.y[i]) return true;
    }
    return false;
}
void Bot::draw(std::string (&board)[HEIGHT]){
    for(int i = 0; i < body; i++){
        if(x[i] == -1 || y[i] == -1) continue;
        if(board[x[i]][y[i]] == VOID) board[x[i]][y[i]] = BOT_BODY;
    }
}
bool Bot::islegible(Player &player, int nextX, int nextY){
    for(int i = 4; i < body; i++){
       if(nextX == x[i] && nextY == y[i]) return true;
    }
    for(int i = 4; i < player.body; i++){
       if(nextX == player.x[i] && nextY == player.y[i]) return true;
    }
    return false;
}