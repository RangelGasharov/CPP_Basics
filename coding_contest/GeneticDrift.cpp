#include <iostream>
#include <vector>
#include <string>

std::vector<int> getPermutations(std::string permutationString) {
    std::string currentNumberAsString;
    int currentNumber = 0;
    std::vector<int> result;
    for (int i = 0; i < permutationString.size(); i++) {
        if (permutationString[i] != ' ') {
            currentNumberAsString += permutationString[i];
        } else {
            currentNumber = std::stoi(currentNumberAsString);
            result.push_back(currentNumber);
            currentNumberAsString = "";
        }
    }
    currentNumber = std::stoi(currentNumberAsString);
    result.push_back(currentNumber);
    currentNumberAsString = "";
    return result;
}

void printPermutations(std::vector<int> permutations) {
    for (int i = 0; i < permutations.size(); i++) {
        std::cout << permutations[i] << std::endl;
    }
}

int main() {
    std::vector<int> permutations = getPermutations("12 34 45 90");
    printPermutations(permutations);
    return 0;
}
