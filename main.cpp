#include <bits/stdc++.h>
#include "KeyHandler.h"
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";
std::string board[] = {"111111111111111111",
                       "1                1",
                       "1                1",
                       "1                1",
                       "1                1",
                       "1                1",
                       "111111111111111111"};

int main() {
    KeyHandler key;
    int playerX = 1, playerY = 1;
    while (true) {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 18; j++)
            {
                if(i == playerX && j == playerY) std::cout << RED << "\u263A";
                else if(board[i][j] == '1') std::cout << BLUE << "\u2588" << RESET;
                else std::cout << board[i][j] << RESET;
            }
            std::cout << std::endl;
        }
        
        Direction input = key.get_input();
        if(input == North){
            playerX--;
        }else if(input == South){
            playerX++;
        }else if(input == West){
            playerY--;
        }else if(input == East){
            playerY++;
        }
        system("clear");
    }    
}