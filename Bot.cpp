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
    y[0] = 48;
}
Bot::~Bot(){

}
/**
 * @brief updates the direction of the bot snake according to the difficulty, bot 
 * chooses the best route and depending on the difficulty it will make some number of random moves.
 * 
 * @param appleX 
 * @param appleY 
 * @param difficulty 
 */
void Bot::update_direction(int appleX, int appleY, int difficulty) {
    int botX = x[0];
    int botY = y[0];
    srand(time(NULL));
    
    //difficulty formula
    int flag = rand() % ((3 * difficulty + 1)/ 2);
    if(difficulty == 5) flag = 1;

    int distanceX = appleX - botX;
    int distanceY = appleY - botY;

    int nextX = botX + (distanceX > 0 ? 1 : -1); 
    int nextY = botY + (distanceY > 0 ? 1 : -1); 
    if(flag){
        if (abs(distanceX) > abs(distanceY)) {

            if (nextX >= 0 && nextX < HEIGHT && islegible(this->direction, (distanceX > 0 ? South : North))) {
                this->direction = (distanceX > 0 ? South : North);
            } else if (nextY >= 0 && nextY < HEIGHT && islegible(this->direction, (distanceY > 0 ? East : West))) {
                this->direction = (distanceY > 0 ? East : West);
            }
        } else {

            if (nextY >= 0 && nextY < WIDTH && islegible(this->direction, (distanceY > 0 ? East : West))) {
                this->direction = (distanceY > 0 ? East : West);
            } else if (nextX >= 0 && nextX < WIDTH && islegible(this->direction, (distanceX > 0 ? South : North))) {
                this->direction = (distanceX > 0 ? South : North);
            }
        }
    }else{
        this->direction = (Direction)(rand() % 4);
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

void Bot::draw(std::string (&board)[HEIGHT]){
    for(int i = 0; i < body; i++){
        if(x[i] == -1 || y[i] == -1) continue;
        if(board[x[i]][y[i]] == VOID) board[x[i]][y[i]] = BOT_BODY;
    }
}
/**
 * @brief Check that whether snake goes into itself or not
 * 
 * @param before 
 * @param after 
 * @return true 
 * @return false 
 */
bool Bot::islegible(Direction before, Direction after){
    return (std::max(before, after) - std::min(before, after)) != 2;
}
