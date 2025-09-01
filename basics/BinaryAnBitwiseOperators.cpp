#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>

void printRow(const std::string &label, int value, int width = 8)
{
    std::cout << std::left << std::setw(16) << label
              << std::bitset<8>(value) << "    "
              << value << "\n";
}

int main()
{
    int x = 6;
    int y = 12;
    int z = 0;

    std::cout << "Start\n";
    printRow("", x);
    printRow("", y);

    printRow("AND", x & y);
    printRow("OR", x | y);
    printRow("XOR", x ^ y);
    printRow("LEFT SHIFT", x << 1);
    printRow("RIGHT SHIFT", x >> 1);

    return 0;
}