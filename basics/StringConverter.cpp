#include <iostream>
#include <string>

using namespace std;

tuple<int, int, int> getComponents(string numberCombination) {
    int originDoor, checkedUntil, nextDoor;
    int separatorOne, separatorTwo;

    for (int i = 0; i <= numberCombination.size() - 1; i++) {
        if (numberCombination[i] == '_') { separatorOne = i; }
        if (numberCombination[i] == '/') { separatorTwo = i; }
    }

    originDoor = stoi(numberCombination.substr(0, separatorOne));
    checkedUntil = stoi(numberCombination.substr(separatorOne + 1, separatorTwo - separatorOne - 1));
    nextDoor = stoi(numberCombination.substr(separatorTwo + 1, numberCombination.size() - separatorTwo - 1));
    return {originDoor, checkedUntil, nextDoor};
}

int main() {
    std::string numberCombination = "11_33/4123";
    int originDoor;
    int checkedUntil;
    int nextDoor;

    auto [value1, value2, value3] = getComponents(numberCombination);

    originDoor = value1;
    checkedUntil = value2;
    nextDoor = value3;

    std::cout << originDoor << std::endl;
    std::cout << checkedUntil << std::endl;
    std::cout << nextDoor << std::endl;

    return 0;
}