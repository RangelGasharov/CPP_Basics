#include <iostream>
#include <vector>

void printPattern(int rows, int cols) {
    // Printing the pattern
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (j <= i && j < cols) {
                std::cout << "[" << i << "," << j << "] ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows, cols;
    std::cout << "Bitte geben Sie die Anzahl der Zeilen ein: ";
    std::cin >> rows;
    std::cout << "Bitte geben Sie die Anzahl der Spalten ein: ";
    std::cin >> cols;

    printPattern(rows, cols);

    return 0;
}
