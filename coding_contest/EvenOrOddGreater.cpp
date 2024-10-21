#include <string>
#include <iostream>

std::string evenOrOdd(std::string str) {
    int sumEven{0}, sumOdd{0};
    for (int i = 0; i < str.length(); i++) {
        char currentNumberAsChar = str[i];
        int currentNumber = currentNumberAsChar - '0';
        if (currentNumber % 2 == 0) {
            sumEven += currentNumber;
        } else {
            sumOdd += currentNumber;
        }
    }
    if (sumEven > sumOdd) {
        return "Even is greater than Odd";
    } else if (sumOdd > sumEven) {
        return "Odd is greater than Even";
    } else {
        return "Even and Odd are the same";
    }
}

int main() {
    std::cout << evenOrOdd("132");
    return 0;
}