#include <bits/stdc++.h>
#include <unistd.h>
#include "KeyHandler.h"
#include "Player.h"
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";
std::string board[] = {"111111111111111111111111111111111111111111111111111111",
                       "1                                                    1",
                       "1                                                    1",
                       "1                                                    1",
                       "1                                                    1",
                       "1                                                    1",
                       "1                                                    1",
                       "1                                                    1",
                       "1                                                    1",
                       "1                                                    1",
                       "1                                                    1",
                       "111111111111111111111111111111111111111111111111111111",};
int main() {
    KeyHandler key;
    Player player;
    while (true) {
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 55; j++)
            {
                if(i == player.x[0] && j == player.y[0]) std::cout << RED << "\u2588";
                else if(i == player.x[1] && j == player.y[1]) std::cout << RED << "\u2588";
                else if(i == player.x[2] && j == player.y[2]) std::cout << RED << "\u2588";
                else if(board[i][j] == '1') std::cout << BLUE << "\u2588" << RESET;
                else std::cout << board[i][j] << RESET;
            }
            std::cout << std::endl;
        }
        
        player.update_body();
        usleep(1000 * 100);
        system("clear");
    }    
}