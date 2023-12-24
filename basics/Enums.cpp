#include <iostream>

enum Color {
    RED, GREEN, BLUE, PURPLE, YELLOW, ORANGE, PINK, BROWN
};

int main() {
    Color myColor = BLUE;
    std::cout << myColor << std::endl;
    myColor = YELLOW;
    std::cout << myColor << std::endl;
    std::cout << ORANGE << std::endl;

    return 0;
}
