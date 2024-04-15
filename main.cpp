#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "Game.h"
#include "Game_Data.h"
#include <chrono>
#include <thread>
using namespace std;
struct termios t;
void reset_terminal(){
    printf("\e[m"); // reset color changes
    printf("\e[?25h"); // show cursor
    fflush(stdout);
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

}
void configure_terminal(){
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    printf("\e[?25l"); // hide cursor
}

void printWithSuspense(const string& text, int delayMs) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}
int main() {
    int choice = 1, difficulty = 1;
    bool exitMenu = false;
    int delay1 = 100;
    int delay2 = 10;
    string message1 = "Printing with suspense...\n"
                       "new line\n"
                       "lol...\n"
                       "new line\n";
    string message2 = "Printing with suspense...\n"
                       "new line\n"
                       "lol...\n"
                       "new line\n";

    configure_terminal();

    // Print the menu once
    cout << CYAN << "███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗" << endl;
    cout << "██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl;
    cout << "███████╗██╔██╗ ██║███████║█████╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗  " << endl;
    cout << "╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
    cout << "███████║██║ ╚████║██║  ██║██║  ██╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl;
    cout << "╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝" <<  RESET << endl;


    cout << "=== Main Menu ===" << endl;
    cout << "1. Play" << endl;
    cout << "2. Story" << endl;
    cout << "3. Tutorial" << endl;
    cout << "4. Difficulty" << endl;
    cout << "5. Exit" << endl;

    while (!exitMenu) {
        // Read a single character from the terminal
        char input;
        int result;
        read(STDIN_FILENO, &input, 1);


        switch (input) {
            case 'w':
                if (choice > 1) {
                    choice--;
                }
                break;
            case 's':
                if (choice < 5) {
                    choice++;
                }
                break;
            case '\n': // Enter key
                switch (choice) {
                    case 1:
                        result = run_game(difficulty);
                        if(result == 0) printWithSuspense("You Won!!!", delay1);
                        else if(result == 1) printWithSuspense("You Lost :(((", delay1);
                        else printWithSuspense("Draw", delay1);
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore();
                        break;
                    case 2:
                        system("clear"); 
                        printWithSuspense(message1, delay1);
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore();
                        break;

                    case 3:
                        system("clear");
                        printWithSuspense(message2, delay2);
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore();
                        break;
                    case 4:
                        system("clear"); 
                        std::cout << "=== Difficulty Menu ===" << std::endl;
                        for (int i = 1; i <= 5; i++) {
                            if (i == difficulty) {
                                std::cout << "> ";
                            }
                            std::cout << i << ". ";
                            switch (i) {
                                case 1:
                                    std::cout << "Beginner";
                                    break;
                                case 2:
                                    std::cout << "Easy";
                                    break;
                                case 3:
                                    std::cout << "Normal";
                                    break;
                                case 4:
                                    std::cout << "Hard";
                                    break;
                                case 5:
                                    std::cout << "Insane";
                                    break;
                            }
                            std::cout << std::endl;
                        }
                        read(STDIN_FILENO, &input, 1);
                        while (input != '\n')
                        {
                            if(input == 'w' && difficulty > 1) difficulty--;
                            else if(input == 's' && difficulty < 5) difficulty++;
                            system("clear"); 
                            std::cout << "=== Difficulty Menu ===" << std::endl;
                            for (int i = 1; i <= 5; i++) {
                                if (i == difficulty) {
                                    std::cout << "> ";
                                }
                                std::cout << i << ". ";
                                switch (i) {
                                    case 1:
                                        std::cout << "Beginner";
                                        break;
                                    case 2:
                                        std::cout << "Easy";
                                        break;
                                    case 3:
                                        std::cout << "Normal";
                                        break;
                                    case 4:
                                        std::cout << "Hard";
                                        break;
                                    case 5:
                                        std::cout << "Insane";
                                        break;
                                }
                                std::cout << std::endl;
                            }
                            read(STDIN_FILENO, &input, 1);
                        }
                        break;
                    case 5:
                        // Exit the menu
                        std::cout << "Exiting the menu." << std::endl;
                        exitMenu = true;
                        break;
                }
                break;
        }

        system("clear");
        cout << CYAN << "███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗" << endl;
    cout << "██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl;
    cout << "███████╗██╔██╗ ██║███████║█████╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗  " << endl;
    cout << "╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
    cout << "███████║██║ ╚████║██║  ██║██║  ██╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl;
    cout << "╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝" <<  RESET << endl;
        std::cout << "=== Main Menu ===" << std::endl;
        for (int i = 1; i <= 5; i++) {
            if (i == choice) {
                std::cout << "> ";
            }
            std::cout << i << ". ";
            switch (i) {
                case 1:
                    std::cout << "Play";
                    break;
                case 2:
                    std::cout << "Story";
                    break;
                case 3:
                    std::cout << "Instructions";
                    break;
                case 4:
                    std::cout << "Difficulty";
                    break;
                case 5:
                    std::cout << "Exit";
                    break;
            }
            std::cout << std::endl;
        }
    }

    reset_terminal();

    return 0;
}