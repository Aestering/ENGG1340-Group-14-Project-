#include <iostream>
#include "KeyHandler.h"
int main() {
    KeyHandler key;
    while (true) {
        Direction input = key.get_input();
        std::cout << input << std::endl;
    }

    
}