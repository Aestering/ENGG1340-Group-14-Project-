#include <bits/stdc++.h>
#include <unistd.h>
#include "KeyHandler.h"
#include "Player.h"
#include "Game_Data.h"
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
                       "111111111111111111111111111111111111111111111111111111"};
int main() {
    KeyHandler key;
    Player player;
    while (true) {
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if(i == player.x[0] && j == player.y[0]) std::cout << RED << BLOCK;
                else if(i == player.x[1] && j == player.y[1]) std::cout << RED << BLOCK;
                else if(i == player.x[2] && j == player.y[2]) std::cout << RED << BLOCK;
                else if(board[i][j] == '1') std::cout << BLUE << SHADE << RESET;
                else std::cout << board[i][j] << RESET;
            }
            std::cout << std::endl;
        }
        
        player.update_body();
        usleep(1000 * 100);
        system("clear");
    }    
}