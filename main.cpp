#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "Game.h"
#include <chrono>
#include <thread>
using namespace std;

// Function to enable raw terminal input (disabling echo and line buffering)
void enableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Function to disable raw terminal input (restoring echo and line buffering)
void disableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void printWithSuspense(const string& text, int delayMs) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

int main() {
    int choice = 1;
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

    enableRawMode();

    // Print the menu once
    cout << "███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗" << endl;
    cout << "██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl;
    cout << "███████╗██╔██╗ ██║███████║█████╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗  " << endl;
    cout << "╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
    cout << "███████║██║ ╚████║██║  ██║██║  ██╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl;
    cout << "╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝" << endl;


    cout << "=== Main Menu ===" << endl;
    cout << "1. Play" << endl;
    cout << "2. Story" << endl;
    cout << "3. Tutorial" << endl;
    cout << "4. Exit" << endl;

    while (!exitMenu) {
        // Read a single character from the terminal
        char input;
        read(STDIN_FILENO, &input, 1);


        switch (input) {
            case 'w':
            case 'W':
                if (choice > 1) {
                    choice--;
                }
                break;
            case 's':
            case 'S':
                if (choice < 4) {
                    choice++;
                }
                break;
            case '\n': // Enter key
                switch (choice) {
                    case 1:
                        // Code for Option 1
                        std::cout << "You selected Option 1." << std::endl;
                        // Add your code here for Option 1
                        run();
                        break;
                    case 2:
                        // Code for Option 2
                        cout << "You selected Option 2." << endl;
                        // Add your code here for Option 2
                        system("clear"); // Clear the console screen
                        printWithSuspense(message1, delay1); // Print the items with suspense
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore(); // Wait for user to press Enter
                        break;

                    case 3:
                        // Code for Option 3
                        cout << "You selected Option 3." << endl;
                        // Add your code here for Option 3
                        system("clear"); // Clear the console screen
                        printWithSuspense(message2, delay2);
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore(); // Wait for user to press Enter
                        break;

                    case 4:
                        // Exit the menu
                        std::cout << "Exiting the menu." << std::endl;
                        exitMenu = true;
                        break;
                }
                break;
        }

        // Clear the console screen
        system("clear");
        cout << "███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗" << endl;
        cout << "██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl;
        cout << "███████╗██╔██╗ ██║███████║█████╔╝ █████╗      ██║  ███╗███████║██╔████╔██║█████╗  " << endl;
        cout << "╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
        cout << "███████║██║ ╚████║██║  ██║██║  ██╗███████╗    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl;
        cout << "╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝" << endl;
        // Print the updated menu with the selected choice highlighted
        std::cout << "=== Main Menu ===" << std::endl;
        for (int i = 1; i <= 4; i++) {
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
                    std::cout << "Exit";
                    break;
            }
            std::cout << std::endl;
        }
    }

    disableRawMode();

    return 0;
}