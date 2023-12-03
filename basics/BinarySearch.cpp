#include <iostream>

using namespace std;

int numberArray[] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 6, 6, 7,
                     8, 8, 9, 10, 12, 15, 18, 19, 22, 28, 30};


int binarySearch(const int array[], int numberToFind) {
    int leftIndex = 0;
    int rightIndex = sizeof(numberArray) / sizeof(numberArray[0]) - 1;
    int middleIndex;
    while (leftIndex <= rightIndex) {
        middleIndex = (rightIndex + leftIndex) / 2;
        if (array[middleIndex] == numberToFind) {
            return true;
        } else if (numberToFind > array[middleIndex]) {
            leftIndex = middleIndex + 1;
        } else {
            rightIndex = middleIndex - 1;
        }
    }
    return -1;
}

int main() {
    cout << binarySearch(numberArray, 19) << endl;
    cout << binarySearch(numberArray, 11) << endl;
}